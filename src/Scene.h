#pragma once

#include "Cube.h"
#include <memory>

class Scene
{
public:
	explicit Scene(Camera& camera, bool dayTime);
	void update();
private:
    bool nightTime;
	Camera& camera;
	Cube floor;
    Mesh bunny;
    Mesh cactus;
    Cube cube;
    Mesh sun;
	std::vector<std::unique_ptr<Cube>> brick;
    glm::vec3 sunPosition = glm::vec3(-24.0f, 24.0f, -64.0f);
};

