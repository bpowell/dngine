#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdlib.h>

class Sprite{
	public:
		SDL_Texture *txt = nullptr;
		SDL_Renderer *renderer = nullptr;
		std::string fname;
		SDL_Rect *loc = nullptr;

		Sprite(SDL_Renderer *r, std::string fn){
			renderer = r;
			if(renderer==NULL){
				exit(1);
			}
			fname = fn;
			txt = IMG_LoadTexture(renderer, fname.c_str());
		}

		void render(std::string msg){
			std::cout << msg << std::endl;
			SDL_RenderCopy(renderer, txt, NULL, loc);
		}
};

class Map{
	public:
		SDL_Renderer *renderer = nullptr;
		Sprite *sprite1 = nullptr;

		Map(SDL_Renderer *r){
			renderer = r;
			sprite1 = new Sprite(renderer, "toon.png");
			sprite1->loc->x=sprite1->loc->y=0;
			sprite1->loc->w=sprite1->loc->h=40;
		}

		void render(){
			std::cout << "Map Rendering:";
			sprite1->render("map");
		}
};

class Screen{
	public:
		SDL_Renderer *renderer = nullptr;
		Sprite *sprite1 = nullptr;
		Map *map1 = nullptr;

		Screen(SDL_Renderer *r){
			renderer = r;
			sprite1 = new Sprite(renderer, "toon.png");
			sprite1->loc->x=sprite1->loc->y=400;
			sprite1->loc->w=sprite1->loc->h=40;
		}

		void render(){
			std::cout << "Screen Rendering:";
			sprite1->render("screen");
		}
};

int main(void){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		std::cout << "bad load: " << SDL_GetError();
		return 1;
	}
	SDL_Window *w = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	if(w==NULL){
		std::cout << "bad load: " << SDL_GetError();
		return 1;
	}
	SDL_Renderer *r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
	if(r==NULL){
		std::cout << "bad load: " << SDL_GetError();
		return 1;
	}

	Screen *screen1 = new Screen(r);
	Map *map1 = new Map(r);

	while(1){
		SDL_Event e;
		if(SDL_PollEvent(&e)){
			if(e.type==SDL_QUIT)
				break;
		}

		SDL_RenderClear(r);
		screen1->render();
		map1->render();
		SDL_RenderPresent(r);
	}
	return 0;
}
