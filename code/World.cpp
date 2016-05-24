#include "World.hpp"

World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures()
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 200.f)				
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerAircraft(nullptr)
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::update(sf::Time& deltaTime)
{
	mWorldView.move(0.f, mScrollSpeed * deltaTime.asSeconds());

	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if(position.x <= mWorldBounds.left + 150 || position.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	mSceneGraph.update(deltaTime);
}

void World::loadTextures()
{
	mTextures.load(Textures::Eagle, "../Media/Textures/Eagle.png");
	mTextures.load(Textures::Raptor, "../Media/Textures/Raptor.png");
	mTextures.load(Textures::Desert, "../Media/Textures/Desert.png");
}

void World::buildScene()
{
	for(std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode);
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}	

	// Prepare the tiled background
	sf::Texture& desertTexture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	desertTexture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(desertTexture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));

	// Add two escorting aircrafts, placed relatively to the main player plane
	// Plane on the left
	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Desert, mTextures));
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	// Plane on the right
	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
	rightEscort->setPosition(80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(rightEscort));

}
