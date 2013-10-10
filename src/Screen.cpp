#include <Screen.h>

namespace dngine{
	Screen::Screen(SDL_Renderer *r){
		renderer = r;
		map = NULL;
	}
	
	Screen::~Screen(){
		SDL_DestroyRenderer(renderer);
	}

	SDL_Renderer* Screen::get_renderer(){
		return renderer;
	}

	void Screen::add_sprite(std::string name, Sprite *s){
		sprites.insert(std::pair<std::string,Sprite*>(name,s));
	}

	void Screen::set_map(Map *m){
		map = m;
	}

	void Screen::set_camera_and_follow(SDL_Rect *pos, Sprite *s){
		camera = new Camera(pos);
		camera->set_follow_sprite(s);
	}

	void Screen::remove_sprite(std::string name){
		sprites.erase(name);
	}

	void Screen::render(){
		SDL_RenderClear(renderer);

		if(map!=NULL)
			map->render();

		std::map<std::string, Sprite*>::iterator it;
		for(it=sprites.begin(); it!=sprites.end(); ++it){
			Sprite *sprite = it->second;
			sprite->render();
		}

		SDL_RenderPresent(renderer);
	}
}
