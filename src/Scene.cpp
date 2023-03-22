#include "Scene.h"

Scene::Scene(Camera& camera, bool dayTime) :
    camera(camera),
	floor("../resources/sand.png"),
    bunny("../resources/bunny.png", "../resources/bunny.obj"),
    cactus("../resources/cactus.png", "../resources/cactus.obj"),
    sun("../resources/sun.png", "../resources/sphere.obj"),
    cube("../resources/pattern.png") {

    floor.translate(glm::vec3(0.0f, -1.0f, 0.0f));
    floor.scale(glm::vec3(15.0f, 0.1f, 15.0f));

    for (int i = 0; i < 8; i++)
        brick.emplace_back(std::make_unique<Cube>("../resources/brick.png"));

    brick[0]->translate(glm::vec3(12.0f, 0.0f, -5.0f));
    brick[1]->translate(glm::vec3(-10.0f, 0.0f, -7.0f));
    brick[2]->translate(glm::vec3(8.0f, 0.0f, -5.0f));
    brick[3]->translate(glm::vec3(-6.0f, 0.0f, 1.0f));
    brick[4]->translate(glm::vec3(4.0f, 0.0f, -1.0f));
    brick[5]->translate(glm::vec3(-4.0f, 0.0f, -3.0f));
    brick[6]->translate(glm::vec3(4.0f, 0.0f, 8.0f));
    brick[7]->translate(glm::vec3(10.0f, 0.0f, 3.0f));

    bunny.translate(glm::vec3(0.0f, -1.0f, -10.0f));

    cactus.translate(glm::vec3(-8.0f, -1.0f, 10.0f));
    cactus.scale(glm::vec3(0.1f, 0.1f, 0.1f));

    cube.translate(glm::vec3(9.5f, 2.5f, 10.5f));

    if (dayTime)
    {
        nightTime = false;
        sun.translate(sunPosition);
    } else {
        nightTime = true;
    }
}

void Scene::update()
{
	floor.render(camera);
    bunny.render(camera);
    cactus.render(camera);
    cube.render(camera);

    if (!nightTime)
        sun.render(camera);

    cube.rotate(0.069f, glm::vec3(1.0f, 0.0f, 1.0f));

	for(auto& s : brick)
		s->render(camera);
}
