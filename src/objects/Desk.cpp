#include "Desk.hpp"
#include <GL/glut.h>

bool Desk::load()
{
	return model.load("assets/models/desk.obj");
}

void Desk::draw() const
{
  glColor3f(0.3f, 0.28f, 0.28f);

	model.draw();
}
