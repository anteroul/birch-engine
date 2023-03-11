#pragma once

#ifndef BIRCHENGINE_ENGINE_H
#define BIRCHENGINE_ENGINE_H

#include "Shader.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"

class Engine {
public:
    Engine(int w, int h);
    bool running;
private:
    Window window;
    Camera camera;
    Scene scene;
    SDL_Event e;
    // is camera moving
    bool isMoving = false;
    // variables for updating time
    const int FPS = 1000 / 60; // 60 FPS
    int lastTime = SDL_GetTicks();
    int currentTime;
    int elapsedTime;

    // copies of camera values
    glm::vec3 cameraPosition;
    glm::vec3 cameraFrontVector;

    void update();
    void render();
    void trackInput();
    void updateCamera();
    void updateTime();
};

#endif //BIRCHENGINE_ENGINE_H
