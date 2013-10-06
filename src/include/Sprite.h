#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace dngine{
	class Sprite{
		private:
			SDL_Renderer *renderer;
			std::string filename;
			SDL_Texture *image;
			SDL_Rect *location;
			SDL_Texture *load_image(SDL_Renderer *r);
		public:
			Sprite(SDL_Renderer *r, std::string fname);
			~Sprite();
			SDL_Texture *get_texture();
			void set_location(SDL_Rect *loc);
			void set_location(int x, int y, int h, int w);
			SDL_Rect *get_location() const;
			void render();
	};

	class SpriteSheet : public Sprite{
		private:
			SDL_Rect *clip_size;
		public:
			SpriteSheet(SDL_Renderer *r, std::string fname, SDL_Rect *size);
	};
}

#endif
