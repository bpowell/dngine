#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <Sprite.h>

#include <string>
#include <map>
#include <SDL2/SDL.h>

namespace dngine{
	class Screen{
		private:
			SDL_Renderer *renderer;
			std::map<std::string, Sprite*> sprites;
		public:
			Screen(SDL_Renderer *r);
			~Screen();
			SDL_Renderer *getRenderer();
			void add_sprite(std::string name, Sprite *s);
			void remove_sprite(std::string name);
			void render();
	};
}

#endif
