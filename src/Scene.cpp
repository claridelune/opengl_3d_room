#include <iostream>
#include "Scene.hpp"

Scene::Scene()
{
	// load models
	chair.load();
	blinds.load();
	bed.load();
	desk.load();

	// set transformations
	chair.transform.position = Vector3(2, 0, -2);
	chair.transform.rotation = Vector3(0, 45, 0);
	chair.transform.scale = Vector3(1, 1, 1);

	blinds.transform.position = Vector3(10, 2, -5);
	blinds.transform.rotation = Vector3(0, 45, 0);
	blinds.transform.scale = Vector3(0.1, 0.1, 0.1);

	bed.transform.scale = Vector3(1, 1, 1);

	desk.transform.position = Vector3(5, 0, 0);
	desk.transform.scale = Vector3(0.2, 0.2, 0.2);

	cone.transform.position = Vector3(0, 0, -5);
	cone.transform.scale = Vector3(0.5, 0.5, 0.5);
}

void Scene::draw() const
{
	cone.draw();
	chair.draw();
	blinds.draw();
	bed.draw();
	desk.draw();
}

void Scene::update()
{
	cone.update();
}
