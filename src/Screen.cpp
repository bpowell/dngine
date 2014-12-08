#include <Screen.h>

namespace dngine{
	Screen::Screen(SDL_Renderer_ptr r) : renderer(r) {
	}
	
	Screen::~Screen(){
	}

	SDL_Renderer_ptr Screen::get_renderer(){
		return renderer;
	}

	void Screen::add_sprite(std::string name, Sprite *s){
		sprites.insert(std::pair<std::string,Sprite*>(name,s));
	}

	void Screen::set_camera_and_follow(SDL_Rect_ptr pos, Sprite *s){
		camera = new Camera(pos);
		camera->set_follow_sprite(s);
	}

	void Screen::remove_sprite(std::string name){
		sprites.erase(name);
	}

	void Screen::render(){
		SDL_RenderClear(renderer.get());
		std::map<std::string, Sprite*>::iterator it;

		for(it=sprites.begin(); it!=sprites.end(); ++it){
			Sprite *sprite = it->second;
			sprite->render();
		}

		 SDL_RenderPresent(renderer.get());
	}
}
