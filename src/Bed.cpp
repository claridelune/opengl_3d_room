#include "Bed.hpp"
#include <GL/glut.h>

bool Bed::load()
{
	return model.load("assets/models/bed.obj");
}

void Bed::draw() const
{
	glPushMatrix();
  glColor3f(0.541f, 0.275f, 0.275f);
	transform.apply();

	model.draw();

	glPopMatrix();
}
