#include "../Engine.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    Engine engine(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!engine.ApplicationShouldClose())
        engine.RunApplication();

    return 0;
}
