#include <Game.h>
#include <stdlib.h>
#include <iostream>

namespace dngine{
	Game::Game(std::string name, int width, int height){
		if(SDL_Init(SDL_INIT_VIDEO) < 0){
			std::cout << "Cannot load SDL\n";
			exit(-1);
		}

		window = SDL_Window_ptr(SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0), SDL_DestroyWindow);
	}

	Game::~Game(){
	}

	SDL_Window_ptr Game::get_window(){
		return window;
	}

	Screen* Game::create_screen(std::string name){
		SDL_Renderer_ptr r = SDL_Renderer_ptr(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
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
