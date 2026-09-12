#include <iostream>
#include "Scene.hpp"

Scene::Scene()
{
	// load models
	chair.load();

	// set transformations
	chair.transform.position = Vector3(2, 0, -2);
	chair.transform.rotation = Vector3(0, 45, 0);
	chair.transform.scale = Vector3(2, 2, 2);

	cone.transform.position = Vector3(0, 0, -5);
	cone.transform.scale = Vector3(0.2, 0.2, 0.2);
}

void Scene::draw() const
{
	cone.draw();
	chair.draw();
}
