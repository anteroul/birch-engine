#include "Window.h"
#include <GL/glew.h>
#include <iostream>

Window::Window(int width, int height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "ERROR: Could not initialize SDL!" << std::endl;
        return;
    }

    printf("Window Resolution: %d x %d \n", width, height);

    // Create the window
    window = SDL_CreateWindow("Birch Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "ERROR: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create ctx
    ctx = SDL_GL_CreateContext(window);

    // start glew
    glewInit();

    // update window size
    SDL_GetWindowSize(window, &size.x, &size.y);
    printf("Window created successfully.\n");

    // Lock the mouse to the window
    SDL_SetWindowMouseGrab(window, SDL_TRUE);

    // Enable relative mouse mode
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

Window::~Window() {
    if(window)
        SDL_DestroyWindow(window);

    SDL_Quit();
}

Vec2i Window::swapSize(Vec2i newSize) {
    Vec2i oldSize = size;
    size = newSize;
    return oldSize;
}
