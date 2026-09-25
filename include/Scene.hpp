#ifndef SCENE_HPP
#define SCENE_HPP

#include "Renderable.hpp"
#include "Light.hpp"
#include "Chair.hpp"
#include "Blinds.hpp"
#include "Bed.hpp"
#include "Desk.hpp"
#include "Dresser.hpp"
#include "Lamp.hpp"
#include "Shelf.hpp"
#include "Clock.hpp"
#include "Apple.hpp"
#include "Room.hpp"

#include <vector>

class Scene
{
	private:
		Room room;
		Chair chair;
		Blinds blinds;
		Desk desk;
		Bed bed;
		Apple apple;
		Dresser dresser;
		Lamp lamp;
		Shelf shelf;
		Clock clock;

		Light mainLight;

		std::vector<Renderable *> objects;
		std::vector<Light *> lights;

	public:
		Scene();
		void update();

		const std::vector<Renderable *> &getObjects() const;
		const std::vector<Light *> &getLights() const;

		void rotateLamp();
		void toggleShelfWireframe();
		void toggleAppleWireframe();
};

#endif
