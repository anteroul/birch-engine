#include "Scene.h"

Scene::Scene(Camera& camera) : camera(camera),
	floor("../resources/sand.png")
{
	floor.translate(glm::vec3(0.0f, -1.0f, 0.0f));
	floor.scale(glm::vec3(20.0f, 0.1f, 20.0f));

	for(int i = 0; i < 7; i++)
		brick.emplace_back(std::make_unique<Cube>("../resources/brick.png"));

    brick[0]->translate(glm::vec3(12.0f, 0.0f, -5.0f));
    brick[1]->translate(glm::vec3(-10.0f, 0.0f, -7.0f));
    brick[2]->translate(glm::vec3(8.0f, 0.0f, -5.0f));
    brick[3]->translate(glm::vec3(-6.0f, 0.0f, 1.0f));
    brick[4]->translate(glm::vec3(4.0f, 0.0f, -1.0f));
    brick[5]->translate(glm::vec3(-4.0f, 0.0f, -3.0f));
    brick[6]->translate(glm::vec3(4.0f, 0.0f, 8.0f));
}

void Scene::update()
{
	floor.render(camera);

	for(auto& s : brick)
		s->render(camera);
}
