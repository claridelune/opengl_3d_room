#ifndef SCENE_HPP
#define SCENE_HPP

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

	public:
		Scene();
		void draw() const;
		void update();
		void rotateLamp();
		void toggleShelfWireframe();
		void toggleAppleWireframe();
};

#endif
