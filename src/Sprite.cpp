#include <Sprite.h>

namespace dngine{
	Sprite::Sprite(std::string fname){
		filename = fname;
		image = load_image(filename);
	}

	SDL_Surface* Sprite::load_image(std::string fname){
		SDL_Surface *loaded = NULL, *optimized = NULL;
		loaded = IMG_Load(fname.c_str());

		if(loaded!=NULL){
			optimized = SDL_DisplayFormatAlpha(loaded);
			SDL_FreeSurface(loaded);
		}

		return optimized;
	}
}
