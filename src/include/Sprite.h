#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <string>
#include "SDL/SDL.h"

namespace dngine{
	class Sprite{
		private:
			std::string filename;
			SDL_Surface *image;
		public:
			Sprite(std::string fname);
			void render();
	};
}

#endif
