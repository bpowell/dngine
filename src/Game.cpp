#include <Game.h>
#include <stdlib.h>
#include <iostream>

namespace dngine{
	Game::Game(std::string name, int width, int height){
		if(SDL_Init(SDL_INIT_VIDEO) < 0){
			std::cout << "Cannot load SDL\n";
			exit(-1);
		}

		window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	}

	Game::~Game(){
		SDL_DestroyWindow(window);
	}

	SDL_Window* Game::get_window(){
		return window;
	}

	Screen* Game::create_screen(std::string name){
		SDL_Renderer *r = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		Screen *s = new Screen(r);

		return s;
	}

	void Game::set_screen(Screen *s){
		screen = s;
	}

	void Game::render(){
		screen->render();
	}
}
