#include "Chair.hpp"
#include <GL/glut.h>

bool Chair::load()
{
	return model.load("assets/models/chair.obj");
}

void Chair::draw() const
{
  glColor3f(0.0f, 0.0f, 0.0f);

	model.draw();
}
