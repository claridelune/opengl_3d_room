#include <iostream>
#include "Scene.hpp"

Scene::Scene() : room(20.0f, 10.0f, 15.0f)
{
	// load models
	chair.load();
	blinds.load();
	bed.load();
	desk.load();
	cat.load();

	// set transformations
	chair.transform.position = Vector3(4.5, room.floorY(), room.backZ() + 3.5);
	chair.transform.rotation = Vector3(-90,0, 180);
	chair.transform.scale = Vector3(0.035f, 0.035f, 0.035f);
	chair.material.diffuse = Vector3(1.0f, 1.0f, 1.0f);

	blinds.transform.position = Vector3(5, 5, room.backZ() + 0.05f);
	blinds.transform.rotation = Vector3(90, 0, 180);
	blinds.transform.scale = Vector3(0.08f, 0.08f, 0.08f);
	blinds.material.diffuse = Vector3(1.0f, 1.0f, 1.0f);

	bed.transform.position = Vector3(-4.5, room.floorY() + 1.2, room.backZ() + 3.5f);
	bed.transform.rotation = Vector3(1, 1, 1);
	bed.transform.scale = Vector3(2, 2, 2);
	bed.material.diffuse = Vector3(1.0f, 1.0f, 1.0f);

	desk.transform.position = Vector3(5, room.floorY() - 0.5f, room.backZ() + 1.2f);
	desk.transform.scale = Vector3(0.5, 0.5, 0.5);
	desk.material.diffuse = Vector3(1.0f, 1.0f, 1.0f);

	apple.transform.position = Vector3(2.7f, 2.35, room.backZ() + 1);
	apple.transform.rotation = Vector3(0, 90, 0);
	apple.transform.scale = Vector3(0.02f, 0.02f, 0.02f);
	apple.material.ambient = Vector3(0.2f, 0.02f, 0.02f);
	apple.material.diffuse = Vector3(1.0f, 1.0f, 1.0f);
	apple.material.specular = Vector3(1.0f, 1.0f, 1.0f);
	apple.material.shininess = 80.0f;

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

	cat.transform.position = Vector3( -4.5f, room.floorY() + 1.65f, room.backZ() + 3.5f);
	cat.transform.scale = Vector3( 0.0025f, 0.0025f, 0.0025f);
	cat.setBaseY(room.floorY() + 1.370f);
	cat.setMovementLimits( -5.5f, -3.2f);

	plant.transform.position = Vector3( 8.8f, room.floorY(), room.backZ() + 0.8f);
	plant.transform.rotation = Vector3( 0.0f, 0.0f, 0.0f);
	plant.transform.scale = Vector3( 0.6f, 0.6f, 0.6f);

	glassLamp.transform.position = Vector3( 6.5f, room.floorY() + 2.150f, room.backZ() + 1.3f);
	glassLamp.transform.rotation = Vector3( 0.0f, 0.0f, 0.0f);
	glassLamp.transform.scale = Vector3( 0.75f, 0.75f, 0.75f);

	mainLight.transform.position = Vector3(0,7,-5);
	mainLight.diffuse = Vector3(1,1,1);
	mainLight.specular = Vector3(1,1,1);
	mainLight.intensity = 0.40f;

	objects.push_back(&room);
	objects.push_back(&chair);
	objects.push_back(&blinds);
	objects.push_back(&bed);
	objects.push_back(&desk);
	objects.push_back(&apple);
	objects.push_back(&dresser);
	objects.push_back(&lamp);
	objects.push_back(&shelf);
	objects.push_back(&clock);
	objects.push_back(&cat);
	objects.push_back(&plant);
	objects.push_back(&glassLamp);

	lights.push_back(&mainLight);
	lights.push_back(&lamp.getLight());
}

const std::vector<Renderable *> &Scene::getObjects() const
{
	return objects;
}

const std::vector<Light *> &Scene::getLights() const
{
	return lights;
}

bool Scene::initialize()
{
	if (!appleTexture.load("assets/textures/apple.jpg")) return false;
	if (!chairTexture.load("assets/textures/chair.jpg")) return false;
	if (!bedTexture.load("assets/textures/bed.jpg")) return false;
	if (!deskTexture.load("assets/textures/desk.jpg")) return false;
	if (!windowTexture.load("assets/textures/window.jpg")) return false;
	if (!dresserTexture.load("assets/textures/dresser.jpg")) return false;

	apple.material.texture = &appleTexture;
	chair.material.texture = &chairTexture;
	bed.material.texture = &bedTexture;
	desk.material.texture = &deskTexture;
	blinds.material.texture = &windowTexture;
	dresser.material.texture = &dresserTexture;

	return true;
}

void Scene::update()
{
	clock.update();
	cat.update();
	lamp.update();
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
