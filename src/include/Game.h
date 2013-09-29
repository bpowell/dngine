#ifndef _GAME_H_
#define _GAME_H_

#include <Screen.h>
#include <string>
#include <SDL2/SDL.h>

namespace dngine{
	class Game{
		private:
			SDL_Window *window;
			Screen *screen;
		public:
			Game(std::string name, int width, int height);
			~Game();
			SDL_Window *get_window();
			void set_screen(Screen *s);
	};
}

#endif
