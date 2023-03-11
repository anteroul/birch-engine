#pragma once

#include "Vector2.h"
#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(int width, int height);
    ~Window();
    bool valid() { return window; }
    // set new window size and return old size
    Vec2i swapSize(Vec2i newSize);
    Vec2i getSize() { return size; }
    SDL_Window *window;
private:
    Vec2i size;
    SDL_GLContext ctx;
};


