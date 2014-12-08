#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <SDL2/SDL.h>
#include <memory>

typedef std::shared_ptr<SDL_Window> SDL_Window_ptr;
typedef std::shared_ptr<SDL_Renderer> SDL_Renderer_ptr;
typedef std::shared_ptr<SDL_Texture> SDL_Texture_ptr;
typedef std::shared_ptr<SDL_Rect> SDL_Rect_ptr;

static SDL_Rect_ptr SDL_RECT(int x, int y, int w, int h) {
    SDL_Rect_ptr rect = SDL_Rect_ptr(new SDL_Rect());
    rect->x=x;
    rect->y=y;
    rect->w=w;
    rect->h=h;

    return rect;
}

#endif
