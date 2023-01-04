#include "Object.h"

void Object::render(float x, float y) const
{
    const float halfSize = edgeSize / 2.0f;
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - edgeSize - halfSize, y - edgeSize - halfSize);
    glVertex2f(x, y + edgeSize * 2.0f);
    glVertex2f(x + edgeSize + halfSize, y - edgeSize - halfSize);
    glEnd();
}
