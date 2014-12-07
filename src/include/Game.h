#ifndef _GAME_H_
#define _GAME_H_

#include <Screen.h>
#include <string>
#include <SDL2/SDL.h>

#include <global.h>

namespace dngine{
	class Game{
		private:
			SDL_Window_ptr window;
			Screen *screen;
		public:
			Game(std::string name, int width, int height);
			~Game();
			SDL_Window_ptr get_window();
			Screen *create_screen(std::string name);
			void set_screen(Screen *s);
			void render();
	};
}

#endif
