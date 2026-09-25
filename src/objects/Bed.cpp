#include "Bed.hpp"
#include <GL/glut.h>

bool Bed::load()
{
	return model.load("assets/models/bed.obj");
}

void Bed::draw() const
{
  glColor3f(0.541f, 0.275f, 0.275f);

	model.draw();
}
