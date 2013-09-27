#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
#include <SDL2/SDL.h>

namespace dngine{
	class Screen{
		private:
			std::string screen_name;
			SDL_Renderer *renderer;
		public:
			Screen(SDL_Window *win, std::string name);
			~Screen();
			SDL_Renderer *getRenderer();
	};
}

#endif
