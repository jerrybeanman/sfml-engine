#ifndef SCENENODE
#define SCENENODE

#include "assert.h"

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class SceneNode
{
		public:
			typedef std::unique_ptr<SceneNode> Ptr;

		public:
								SceneNode();
			void 				attachChild(Ptr child);
			Ptr					detachChild(const SceneNode& node);

		private:
			std::vector<Ptr> 	mChildren;
			SceneNode* 			mParent;
};

#endif //SCENENODE
