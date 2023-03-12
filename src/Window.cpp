#include "Window.h"
#include <GL/glew.h>
#include <cstdio>

Window::Window(int width, int height)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("ERROR: Could not initialize SDL!\n");
        return;
    }

    printf("Window Resolution: %d x %d \n", width, height);

    // Create the window
    window = SDL_CreateWindow("Birch Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_OPENGL);

    if (!window)
    {
        printf("ERROR: %s\n", SDL_GetError());
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create ctx
    SDL_GL_CreateContext(window);

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

Window::~Window()
{
    if(window)
        SDL_DestroyWindow(window);

    SDL_Quit();
    printf("Application closed successfully.\n");
}