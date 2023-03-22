#include "../Engine.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define DAY 0
#define NIGHT 1
#define EVENING 2

int main()
{
    Engine engine(WINDOW_WIDTH, WINDOW_HEIGHT, DAY);

    while (!engine.ApplicationShouldClose())
        engine.RunApplication();

    return 0;
}
