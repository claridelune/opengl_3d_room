#include <iostream>
#include "Scene.hpp"

Scene::Scene() : room(20.0f, 10.0f, 15.0f)
{
	// load models
	chair.load();
	blinds.load();
	bed.load();
	desk.load();

	// set transformations
	chair.transform.position = Vector3(4.5, room.floorY() + 1.5f, room.backZ() + 3);
	chair.transform.rotation = Vector3(0, -180, 0);
	chair.transform.scale = Vector3(3, 3, 3);

	blinds.transform.position = Vector3(5, 3, room.backZ() + 0.5f);
	blinds.transform.rotation = Vector3(0, 90, 0);
	blinds.transform.scale = Vector3(0.4, 0.2, 0.2);

	bed.transform.position = Vector3(-4.5, room.floorY() + 1.2, room.backZ() + 3.5f);
	bed.transform.rotation = Vector3(1, 1, 1);
	bed.transform.scale = Vector3(2, 2, 2);

	desk.transform.position = Vector3(5, room.floorY() - 0.5f, room.backZ() + 0.5f);
	desk.transform.scale = Vector3(0.5, 0.5, 0.5);

	apple.transform.position = Vector3(2.7f, 2.35, room.backZ() + 1);
	apple.transform.rotation = Vector3(0, 90, 0);
	apple.transform.scale = Vector3(0.02f, 0.02f, 0.02f);

	dresser.transform.position = Vector3(room.leftX() + 1.5f, 0.0f, room.backZ() + 0.5f);
	dresser.transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	dresser.transform.scale = Vector3(2.0f, 2.0f, 2.0f);

	lamp.transform.position = Vector3(room.leftX() + 1.5f, 2.6f, room.backZ() + 0.5f);
	lamp.transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	lamp.transform.scale = Vector3(1.3f, 1.3f, 1.3f);

	shelf.transform.position = Vector3( room.rightX() - 0.5f, room.floorY(), -7.0f);
	shelf.transform.rotation = Vector3( 0.0f, 90.0f, 0.0f);
	shelf.transform.scale = Vector3( 3.0f, 3.0f, 1.0f);

	clock.transform.position = Vector3( room.leftX(), 7, room.backZ() + 4);
	clock.transform.rotation = Vector3( 0.0f, 90.0f, 0.0f);
	clock.transform.scale = Vector3( 1.5f, 1.5f, 1.5f);
}

void Scene::draw() const
{
	room.draw();
	chair.draw();
	blinds.draw();
	bed.draw();
	desk.draw();
	apple.draw();
	dresser.draw();
	lamp.draw();
	shelf.draw();
	clock.draw();
}

void Scene::update()
{
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

void Scene::toggleAppleWireframe()
{
	apple.toggleWireframe();
}
