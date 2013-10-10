#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <Sprite.h>
#include <Camera.h>
#include <Map.h>

#include <string>
#include <map>
#include <SDL2/SDL.h>

namespace dngine{
	class Screen{
		private:
			SDL_Renderer *renderer;
			std::map<std::string, Sprite*> sprites;
			Camera *camera;
			Map *map;
		public:
			Screen(SDL_Renderer *r);
			~Screen();
			SDL_Renderer *get_renderer();
			void add_sprite(std::string name, Sprite *s);
			void set_map(Map *m);
			void set_camera_and_follow(SDL_Rect *pos, Sprite *s);
			void remove_sprite(std::string name);
			void render();
	};
}

#endif
