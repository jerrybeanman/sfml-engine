#include "Game.hpp"
#include "StringHelpers.hpp"

#include <iostream>

Game::Game()
:	mWindow(sf::VideoMode(640, 480), "hi im a elizabeth")
, 	mWorld(mWindow)
, 	mFont()
,	mStatisticsText()
, 	mStatisticsUpdateTime()
, 	mStatisticsNumFrames(0)
{

	mFont.loadFromFile("../Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(20);

}


void Game::Run()
{
	sf::Clock 	clock;
	sf::Time 	timeSinceLastUpdate = sf::Time::Zero;
	
	while(mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while(timeSinceLastUpdate > TimePerFrame)
		{
			processEvents();
			timeSinceLastUpdate -= TimePerFrame;
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
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
	mWorld.update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames++;

	if(mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString("Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
									"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;

	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
}



















