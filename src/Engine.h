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
    void RunApplication();
    bool ApplicationShouldClose() const;
private:
    void render();
    void trackInput();
    void updateCamera();
    bool running;
    Window window;
    Camera camera;
    Scene scene;
    glm::vec3 cameraPosition;
    glm::vec3 cameraFrontVector{};
    bool viewChanged = false;
};

#endif //BIRCHENGINE_ENGINE_H
