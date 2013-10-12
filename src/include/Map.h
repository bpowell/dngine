#ifndef _MAP_H_
#define _MAP_H_

#include <Sprite.h>

#include <string>
#include <map>
#include <boost/multi_array.hpp>
#include <SDL2/SDL.h>

namespace dngine{
	class Map{
		private:
			typedef boost::multi_array<int, 2> map_array;
			typedef map_array::index map_index;
			typedef std::map<std::string,std::string> properties;
			typedef std::map<int, properties> tile_properties;

			std::string filename;
			std::string map_name;
			std::string tilesheet;
			SpriteSheet *spritesheet;
			SDL_Renderer *renderer;
			int width;
			int height;
			map_array map_layout;
			tile_properties tile_info;

			void load();
			void load_spritesheet();
		public:
			Map(std::string name, SDL_Renderer *r);
	};
}

#endif
