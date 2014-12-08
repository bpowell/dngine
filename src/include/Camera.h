#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <Sprite.h>
#include <SDL2/SDL.h>

namespace dngine{
	class Camera{
		private:
			SDL_Rect_ptr camera;
			Sprite *sprite;
		public:
			Camera(int x, int y, int w, int h);
			Camera(SDL_Rect_ptr c);
			void set_follow_sprite(Sprite *s);
			void update();
	};
}

#endif
