#pragma once

#include "Cube.h"
#include <memory>

class Scene
{
public:
	explicit Scene(Camera& camera);
	void update();
private:
	Camera& camera;
	Cube floor;
    Mesh bunny;
    Mesh cactus;
    Cube cube;
	std::vector<std::unique_ptr<Cube>> brick;
};

