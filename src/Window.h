#pragma once

#include "Vector2.h"
#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(int width, int height);
    ~Window();
    SDL_Window *window;
private:
    Vec2i size;
};


