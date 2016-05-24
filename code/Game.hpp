#ifndef GAME
#define GAME

#include "World.hpp"

#include <SFML/Graphics.hpp>

// updates 60 times per frame
static const sf::Time	TimePerFrame  = sf::seconds(1.f / 60.f);

class Game
{
		public:
								Game();
			void 				Run();

		private:
			void				processEvents();
			void 				update(sf::Time deltaTime);
			void 				render();

			void 				updateStatistics(sf::Time elapsedTime);
			void 				handlePlayerInput(sf::Keyboard::Key, bool isPressed);

		private:
			sf::RenderWindow 	mWindow;
			World 				mWorld;

			sf::Font 			mFont;
			sf::Text 			mStatisticsText;
			sf::Time 			mStatisticsUpdateTime;
			std::size_t			mStatisticsNumFrames;

};

#endif
