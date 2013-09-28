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

	void Screen::remove_sprite(std::string name){
		sprites.erase(name);
	}

	void Screen::render(){
		SDL_RenderClear(renderer);
		std::map<std::string, Sprite*>::iterator it;

		for(it=sprites.begin(); it!=sprites.end(); ++it){
			Sprite *sprite = it->second;
			SDL_RenderCopy(renderer, sprite->getTexture(), NULL, sprite->getLocation());
		}

		 SDL_RenderPresent(renderer);
	}
}
