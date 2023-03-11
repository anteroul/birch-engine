#pragma once

#include "Cube.h"
#include <memory>

class Scene
{
public:
	Scene(Camera& camera);
	void update();
private:
	Camera& camera;
	Cube floor;
	std::vector<std::unique_ptr<Cube>> brick;
};

