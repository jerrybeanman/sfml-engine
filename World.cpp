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

void World::loadTextures()
{
	mTextures.load(Textures::Eagle, "Media/Textures/Eagle.png");
	mTextures.load(Textures::Eagle, "Media/Textures/Raptor.png");
	mTextures.load(Textures::Eagle, "Media/Textures/Desert.png");
}

void World::buildScene()
{
	for(std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode);
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}	

	sf::Texture& desertTexture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	desertTexture.setRepeated(true);
}
