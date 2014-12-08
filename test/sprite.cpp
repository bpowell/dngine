#include <Sprite.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH 800
#define HEIGHT 600

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;
	SDL_Window_ptr win;
	SDL_Renderer_ptr renderer;
	win = SDL_Window_ptr(SDL_CreateWindow("Image Loading", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0), SDL_DestroyWindow);
	renderer = SDL_Renderer_ptr(SDL_CreateRenderer(win.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
	dngine::Sprite *s = new dngine::Sprite(renderer, "toon.png");
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

		// clear the screen
		SDL_RenderClear(renderer.get());
		// copy the texture to the rendering context
		// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
		SDL_RenderPresent(renderer.get());

	}

	delete s;
	return 0;
}
