#include "Blinds.hpp"
#include <GL/glut.h>

bool Blinds::load()
{
	return model.load("assets/models/window.obj");
}

void Blinds::draw() const
{
	glPushMatrix();
  glColor3f(0.65f, 0.42f, 0.153f);
	transform.apply();

	model.draw();

	glPopMatrix();
}
