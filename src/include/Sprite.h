#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

namespace dngine{
	class Sprite{
		private:
			std::string filename;
			SDL_Surface *image;
			SDL_Surface *load_image(std::string fname);
		public:
			Sprite(std::string fname);
			void render();
	};
}

#endif
