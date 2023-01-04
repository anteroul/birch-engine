#include "Engine.h"

Engine::Engine(int w, int h)
{
    glfwInit();
    GLFWwindow* window;

    // Initialize glfw:
    if (!glfwInit())
    {
        printf("Failed to initialize glfw!\n");
        return;
    }

    // Create a new window:
    window = glfwCreateWindow(w, h, "Birch Engine", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    printf("Window created with a resolution of %d x %d \n", w, h);

    // Make the window's context current:
    glfwMakeContextCurrent(window);

    // Get keyboard input:
    //glfwSetKeyCallback(window, Engine::KeyCallback);

    // Game loop:
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        UpdateObject(firstObject, MOVE_HORIZONTAL);
        UpdateObject(secondObject, ROTATE);
        UpdateObject(thirdObject, MOVE_VERTICAL);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

Engine::~Engine() {
    glfwTerminate();
    printf("Program terminated successfully.");
}

void Engine::UpdateObject(Object &obj, behavior b)
{
    if (b == MOVE_VERTICAL)
    {
        if (!obj.destinationPassed) {
            if (obj.posY <= obj.posY * -1 + 0.5f)
                obj.posY += movingSpeed;
            else
                obj.destinationPassed = true;
        } else {
            if (obj.posY >= obj.posY * -1 - 0.5f)
                obj.posY -= movingSpeed;
            else
                obj.destinationPassed = false;
        }
        obj.render(obj.posX, obj.posY);
    } else if (b == MOVE_HORIZONTAL) {
        if (!obj.destinationPassed) {
            if (obj.posX <= obj.posX * -1 + 0.5f)
                obj.posX += movingSpeed;
            else
                obj.destinationPassed = true;
        } else {
            if (obj.posX >= obj.posX * -1 - 1.5f)
                obj.posX -= movingSpeed;
            else
                obj.destinationPassed = false;
        }
        obj.render(obj.posX, obj.posY);
    } else {
        degree += 1000.0f * movingSpeed * 16;

        double radian = degree * M_PI / 180;

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(0.0012f, 0, 0);
        glRotatef((float)radian, 0, 0, 1.0f);
        obj.render(obj.posX, obj.posY);
        glPopMatrix();
        glFlush();
    }
}