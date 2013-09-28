#include <Screen.h>

namespace dngine{
	Screen::Screen(SDL_Window *win, std::string name){
		screen_name = name;
		renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	}
	
	Screen::~Screen(){
		SDL_DestroyRenderer(renderer);
	}

	SDL_Renderer* Screen::getRenderer(){
		return renderer;
	}

	void Screen::add_sprite(std::string name, Sprite *s){
		sprites.insert(std::pair<std::string,Sprite*>(name,s));
	}
}
