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
			void 				handlePlayerInput(sf::Keyboard::Key, bool isPressed);

		private:
			sf::RenderWindow 	mWindow;
			sf::Texture 		mTexture;
			sf::Sprite 			mPlayer;
			bool 				mIsMovingUp;
			bool 				mIsMovingDown;
			bool 				mIsMovingRight;
			bool 				mIsMovingLeft;

};
