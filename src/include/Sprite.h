#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace dngine{
	class Sprite{
		private:
			std::string filename;
			SDL_Texture *image;
			SDL_Texture *load_image(SDL_Renderer *r, std::string fname);
		public:
			Sprite(SDL_Renderer *r, std::string fname);
			SDL_Texture *getTexture();
			void render();
	};
}

#endif
