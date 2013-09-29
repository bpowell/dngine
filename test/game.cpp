#include <Game.h>
#include <Sprite.h>
#include <Screen.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH 800
#define HEIGHT 600

int main()
{
	dngine::Game *game = new dngine::Game("Hello", 800, 600);
	dngine::Screen *screen = new dngine::Screen(game->get_window(), "Main Screen");
	dngine::Sprite *s = new dngine::Sprite(screen->getRenderer(), "toon.png");
	screen->add_sprite("one", s);
	int w, h;
	SDL_QueryTexture(s->getTexture(), NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height
	SDL_Rect texr; texr.x = WIDTH/2; texr.y = HEIGHT/2; texr.w = w*2; texr.h = h*2; 
	s->setLocation(&texr);

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
	delete game;
	return 0;
}

