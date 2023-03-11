#include "Engine.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>


Engine::Engine(int w, int h) :
        running(true), window(w, h),
        camera(),
        scene(camera),
        cameraPosition(glm::vec3(0.0f)) {

    // give a nice background
    glClearColor(0.0f, 0.5f, 0.7f, 1.0f);

    // enable depth testing
    glEnable(GL_DEPTH_TEST);

    while(running)
        update();
}

void Engine::update() {
    updateTime();
    render();
    trackInput();
    updateCamera();
}

void Engine::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene.update();
    // main SDL rendering
    SDL_GL_SwapWindow(window.window);
}

void Engine::trackInput() {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            running = false;

            // movement with WASD keys
        else if (e.type == SDL_KEYDOWN) {
            cameraFrontVector = camera.getNewFrontVector();

            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                    break;

                case SDLK_w:
                    cameraPosition += camera.getSpeed() + cameraFrontVector;
                    isMoving = true;
                    break;
                case SDLK_s:
                    cameraPosition -= camera.getSpeed() + cameraFrontVector;
                    isMoving = true;
                    break;
                case SDLK_a:
                    cameraPosition -= glm::normalize(glm::cross(cameraFrontVector, camera.getUp())) + camera.getSpeed();
                    isMoving = true;
                    break;
                case SDLK_d:
                    cameraPosition += glm::normalize(glm::cross(cameraFrontVector, camera.getUp())) + camera.getSpeed();
                    isMoving = true;
                    break;
            }
        }

            // stop movement
        else if (e.type == SDL_KEYUP) {
            isMoving = false;
            cameraPosition = glm::vec3(0.0f);
        }

            // move camera according to mouse
        else if (e.type == SDL_MOUSEMOTION) {
            camera.processMouseMovement(e.motion.xrel, e.motion.yrel);
        }
    }
}

void Engine::updateCamera() {
    if (isMoving)
        camera.translate(cameraPosition, cameraFrontVector);
}

void Engine::updateTime() {
    currentTime = SDL_GetTicks();
    elapsedTime = currentTime - lastTime;
    lastTime = currentTime;

    // sleep for the remaining FPS
    int elapsedTimeMs = SDL_GetTicks() - currentTime;
    if (elapsedTimeMs < FPS)
        SDL_Delay(FPS - elapsedTimeMs);
}