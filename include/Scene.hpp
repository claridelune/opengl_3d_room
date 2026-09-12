#ifndef SCENE_HPP
#define SCENE_HPP

#include "Cone.hpp"
#include "OBJModel.hpp"

class Scene
{
	private:
		Cone cone;
		OBJModel model;
		// Variables de animación
    	float minuteAngle;
    	float lampAngle;

    	// Funciones auxiliares
    	void drawCube(float x, float y, float z) const;

	public:
		Scene();
		void draw() const;

		// Objetos JesusP
	    void drawComoda() const;
   		void drawLampara() const;
    	void drawEstante() const;
    	void drawReloj() const;

    	// Animación
    	void update();
};

#endif
