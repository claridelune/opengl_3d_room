#include "Desk.hpp"
#include <GL/glut.h>

bool Desk::load()
{
	return model.load("assets/models/desk.obj");
}

void Desk::draw() const
{
	glPushMatrix();
  glColor3f(0.3f, 0.28f, 0.28f);
	transform.apply();

	model.draw();

	glPopMatrix();
}
