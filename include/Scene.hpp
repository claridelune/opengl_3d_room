#ifndef SCENE_HPP
#define SCENE_HPP

#include "Cone.hpp"
#include "Chair.hpp"
#include "Blinds.hpp"
#include "Bed.hpp"
#include "Desk.hpp"
#include "Dresser.hpp"
#include "Lamp.hpp"
#include "Shelf.hpp"
#include "Clock.hpp"

class Scene
{
	private:
		Cone cone;
		Chair chair;
		Blinds blinds;
		Desk desk;
		Bed bed;
		Dresser dresser;
		Lamp lamp;
		Shelf shelf;
		Clock clock;
		// Variables de animación
		float minuteAngle;
		float lampAngle;

		// Funciones auxiliares
		void drawCube(float x, float y, float z) const;

	public:
		Scene();
		void draw() const;
		void update();
		void rotateLamp();
		void toggleShelfWireframe();

		// Objetos JesusP
		void drawComoda() const;
		void drawLampara() const;
		void drawEstante() const;
		void drawReloj() const;
		
};

#endif
