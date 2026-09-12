#include "Chair.hpp"
#include <GL/glut.h>

bool Chair::load()
{
	return model.load("assets/models/chair.obj");
}

void Chair::draw() const
{
	glPushMatrix();
  glColor3f(1.0f, 0.0f, 0.0f);
	transform.apply();

	model.draw();

	glPopMatrix();
}
