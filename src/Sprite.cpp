#include <Sprite.h>

namespace dngine{
	Sprite::Sprite(SDL_Renderer *r, std::string fname){
		filename = fname;
		image = load_image(r, filename);
	}

	SDL_Texture* Sprite::getTexture(){
		return image;
	}

	SDL_Texture* Sprite::load_image(SDL_Renderer *r, std::string fname){
		SDL_Texture *i = IMG_LoadTexture(r, fname.c_str());
		return i;
	}
}
