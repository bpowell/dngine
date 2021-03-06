#include <Sprite.h>
#include <Screen.h>
#include <global.h>
#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

#define WIDTH 800
#define HEIGHT 600

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;
	SDL_Window *win = NULL;
	win = SDL_CreateWindow("Image Loading", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	SDL_Renderer_ptr r = SDL_Renderer_ptr(SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
	dngine::Screen *screen = new dngine::Screen(r);
	dngine::Sprite *s = new dngine::Sprite(screen->get_renderer(), "toon.png");
	screen->add_sprite("one", s);
	int w, h;
	SDL_QueryTexture(s->get_texture().get(), NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height
    SDL_Rect_ptr texr = SDL_RECT(WIDTH/2, HEIGHT/2, w*2, h*2);
	s->set_location(texr);

	// main loop
	while (1) {

		// event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
		} 

		screen->render();

	}

	delete s;
	delete screen;
	SDL_DestroyWindow(win);
	return 0;
}
