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

	dresser.transform.position = Vector3(3.0f, 0.0f, -3.0f);
	dresser.transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	dresser.transform.scale = Vector3(1.0f, 1.0f, 1.0f);

	lamp.transform.position = Vector3(3.0f, 1.30f, -3.0f);
	lamp.transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	lamp.transform.scale = Vector3(0.70f, 0.70f, 0.70f);

	shelf.transform.position = Vector3(
    -3.0f,
    0.0f,
    -3.0f
	);

	shelf.transform.rotation = Vector3(
    0.0f,
    0.0f,
    0.0f
	);

	shelf.transform.scale = Vector3(
    1.0f,
    1.0f,
    1.0f
	);

	clock.transform.position = Vector3(
    0.0f,
    2.5f,
    -3.5f
	);

	clock.transform.rotation = Vector3(
    0.0f,
    0.0f,
    0.0f
	);

	clock.transform.scale = Vector3(
    0.8f,
    0.8f,
    0.8f
	);
}

void Scene::draw() const
{
	cone.draw();
	chair.draw();
	blinds.draw();
	bed.draw();
	desk.draw();
	dresser.draw();
	lamp.draw();
	shelf.draw();
	clock.draw();
}

void Scene::update()
{
	cone.update();
	clock.update();
}

void Scene::rotateLamp()
{
    lamp.rotateUpperPart();
}

void Scene::toggleShelfWireframe()
{
    shelf.toggleWireframe();
}
