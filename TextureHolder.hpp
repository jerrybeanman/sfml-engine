#ifndef RESOURCEHOLDER 
#define RESOURCEHOLDER 

#include <assert.h>

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>


namespace Textures
{
	enum ID{ Landscape, Airplane, Missile };
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
		public:
			void load(Identifier id, const std::string& filename);
			template <typename Parameter>
			void load(Identifier id, const std::string& filename, const Parameter& secondParam);

			Resource& get(Identifier id);
			const Resource& get(Identifier id) const;

		private:
			std::map<Identifier, std::unique_ptr<Resource> > mResourceMap;
};

#endif
