#ifndef BIRCHENGINE_OBJECT_H
#define BIRCHENGINE_OBJECT_H

#include <GLFW/glfw3.h>

struct Object {
    GLfloat r, g, b;
    float posX, posY, edgeSize;
    bool destinationPassed;
    void render(float x, float y) const;
};

#endif //BIRCHENGINE_OBJECT_H
