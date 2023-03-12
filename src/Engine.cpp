#include "Engine.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>


Engine::Engine(int w, int h) :
        running(true), window(w, h),
        camera(),
        scene(camera),
        cameraPosition(glm::vec3(0.0f)) {
    glClearColor(0.0f, 0.5f, 0.7f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void Engine::RunApplication()
{
    while(running)
    {
        render();
        trackInput();
        updateCamera();
    }
}

bool Engine::ApplicationShouldClose() const
{
    if (running)
        return false;

    return true;
}

void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene.update();
    // main SDL rendering
    SDL_GL_SwapWindow(window.window);
}

void Engine::trackInput()
{
    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        cameraFrontVector = camera.getNewFrontVector();

        switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                camera.processMouseMovement(e.motion.xrel, e.motion.yrel);
                viewChanged = true;
                break;
            case SDL_KEYUP:
                viewChanged = false;
                cameraPosition = glm::vec3(0.0f);
                break;
            default:
                break;
        }

        if (state[SDL_SCANCODE_W]) {
            cameraPosition += camera.getSpeed() * cameraFrontVector;
            viewChanged = true;
        }
        if (state[SDL_SCANCODE_S]) {
            cameraPosition -= camera.getSpeed() * cameraFrontVector;
            viewChanged = true;
        }
        if (state[SDL_SCANCODE_A]) {
            cameraPosition -= glm::normalize(glm::cross(cameraFrontVector, camera.getUp())) * camera.getSpeed();
            viewChanged = true;
        }
        if (state[SDL_SCANCODE_D]) {
            cameraPosition += glm::normalize(glm::cross(cameraFrontVector, camera.getUp())) * camera.getSpeed();
            viewChanged = true;
        }
    }
}

void Engine::updateCamera()
{
    if (viewChanged)
        camera.translate(cameraPosition, cameraFrontVector);
}