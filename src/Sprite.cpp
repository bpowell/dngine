#include <Sprite.h>

namespace dngine{
	Sprite::Sprite(SDL_Renderer *r, std::string fname){
		filename = fname;
		image = load_image(r, filename);
	}

	Sprite::~Sprite(){
		SDL_DestroyTexture(image);
	}

	SDL_Texture* Sprite::getTexture(){
		return image;
	}

	void Sprite::setLocation(SDL_Rect *loc){
		location = loc;
	}

	void Sprite::setLocation(int x, int y, int h, int w){
		location->x = x;
		location->y = y;
		location->h = h;
		location->w = w;
	}

	SDL_Rect* Sprite::getLocation() const{
		return location;
	}

	SDL_Texture* Sprite::load_image(SDL_Renderer *r, std::string fname){
		SDL_Texture *i = IMG_LoadTexture(r, fname.c_str());
		return i;
	}
}
