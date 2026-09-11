#include "Cone.hpp"
#include <GL/glut.h>

void Cone::draw() const
{
	glColor3f(0.2f, 0.5f, 1.0f);

	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutWireCone(1.5, 3.0, 24, 8);
	glPopMatrix();
}
