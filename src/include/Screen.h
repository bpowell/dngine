#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <Sprite.h>
#include <Camera.h>
#include <global.h>

#include <string>
#include <map>
#include <SDL2/SDL.h>

namespace dngine{
	class Screen{
		private:
			SDL_Renderer_ptr renderer;
			std::map<std::string, Sprite*> sprites;
			Camera *camera;
		public:
			Screen(SDL_Renderer_ptr r);
			~Screen();
			SDL_Renderer_ptr get_renderer();
			void add_sprite(std::string name, Sprite *s);
			void set_camera_and_follow(SDL_Rect *pos, Sprite *s);
			void remove_sprite(std::string name);
			void render();
	};
}

#endif
