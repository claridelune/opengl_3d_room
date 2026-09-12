#ifndef SCENE_HPP
#define SCENE_HPP

#include "Cone.hpp"
#include "Chair.hpp"

class Scene
{
	private:
		Cone cone;
		Chair chair;
		OBJModel model;
		// Variables de animación
		float minuteAngle;
		float lampAngle;

		// Funciones auxiliares
		void drawCube(float x, float y, float z) const;

	public:
		Scene();
		void draw() const;
		void update();

		// Objetos JesusP
		void drawComoda() const;
		void drawLampara() const;
		void drawEstante() const;
		void drawReloj() const;

};

#endif
