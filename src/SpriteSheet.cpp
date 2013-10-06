#include <Sprite.h>

namespace dngine{
	SpriteSheet::SpriteSheet(SDL_Renderer *r, std::string fname, SDL_Rect *size)
		:Sprite(r, fname){ 
			clip_size = size;
	}
}
