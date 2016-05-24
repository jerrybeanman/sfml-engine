#ifndef ENTITY
#define ENTITY

#include "SceneNode.hpp"

#include <SFML/Graphics.hpp>

class Entity : public SceneNode
{
		public:
			void 			setVelocity(sf::Vector2f velocity);
			void 			setVelocity(float vx, float vy);
			sf::Vector2f 	getVelocity() const;
	
		private:
			virtual void 	updateCurrent(sf::Time deltaTime);

		private:
			sf::Vector2f 	mVelocity;	
			
};

#endif // ENTITY
