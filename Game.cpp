#include <iostream>
#include "Game.hpp"

Game::Game()
:	mWindow(sf::VideoMode(640, 480), "hi im a elizabeth")
,	mTexture()
,	mPlayer()
{
	mIsMovingUp = mIsMovingDown = mIsMovingLeft = mIsMovingRight = false;
	if(!mTexture.loadFromFile("Media/Textures/elizabeth.png"))
	{
		std::cerr << "cant open image" << std::endl;
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
}


void Game::Run()
{
	sf::Clock 	clock;
	sf::Time 	timeSinceLastUpdate = sf::Time::Zero;
	
	while(mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while(timeSinceLastUpdate > TimePerFrame)
		{
			processEvents();
			timeSinceLastUpdate -= TimePerFrame;
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		if(event.type == sf::Event::KeyPressed)
		{
			handlePlayerInput(event.key.code, true);
		}else
		if(event.type == sf::Event::KeyReleased)
		{
			handlePlayerInput(event.key.code, false);
		}else
		if(event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if(mIsMovingUp)
		movement.y -= 100.f;
	if(mIsMovingDown)
		movement.y += 100.f;
	if(mIsMovingLeft)
		movement.x -= 100.f;
	if(mIsMovingRight)
		movement.x += 100.f;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if(key == sf::Keyboard::W)
	{
		mIsMovingUp 	= isPressed;
	}else
	if(key == sf::Keyboard::S)
	{
		mIsMovingDown 	= isPressed;
	}else
	if(key == sf::Keyboard::D)
	{
		mIsMovingRight 	= isPressed;
	}else
	if(key == sf::Keyboard::A)
	{
		mIsMovingLeft 	= isPressed;
	}
}



















