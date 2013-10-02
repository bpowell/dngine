#include <Camera.h>

namespace dngine{
	Camera::Camera(int x, int y, int w, int h){
		camera->x = x;
		camera->y = y;
		camera->w = w;
		camera->h = h;
	}

	Camera::Camera(SDL_Rect *c){
		camera = c;
	}

	void Camera::set_follow_sprite(Sprite *s){
		sprite = s;
	}

	void Camera::update(){
	}
}
