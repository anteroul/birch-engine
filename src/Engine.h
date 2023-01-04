#ifndef BIRCHENGINE_ENGINE_H
#define BIRCHENGINE_ENGINE_H

#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdio>
#include "Object.h"

class Engine {
public:
    Engine(int w, int h);
    ~Engine();
private:
    enum behavior { MOVE_VERTICAL, MOVE_HORIZONTAL, ROTATE };
    //[[maybe_unused]] int keysArePressed[512];
    float movingSpeed = 0.0016f;
    long long degree = 0;
    Object firstObject = {255.f, 0, 0, -0.5f, 0.5f, 0.09f, false};
    Object secondObject = {255.f,255.f, 0,-0.25f, -0.25f, 0.12f, false};
    Object thirdObject = {255.f, 0, 255.f, 0.5f, -0.5f, 0.04f, false};

    void UpdateObject(Object &object, behavior b);
};

#endif //BIRCHENGINE_ENGINE_H
