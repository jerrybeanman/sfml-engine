#ifndef SPRITENODE_HPP
#define SPRITENODE_HPP

#include "SceneNode.hpp"
#include <SFML/Graphics.hpp>

class SpriteNode : public SceneNode
{
		public:
			explicit 			SpriteNode(const sf::Texture& texture);
								SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

		private: 
			virtual void 		drawCurrent(RenderTarget& target, sf::RenderStates& states) const;

		private:
			sf::Sprite 			mSprite;
};

#endif //SPRITENODE_HPP
