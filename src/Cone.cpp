#include "Cone.hpp"
#include <GL/glut.h>

void Cone::draw() const
{
	glColor3f(0.2f, 0.5f, 1.0f);

	glPushMatrix();

	transform.apply();

	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutWireCone(1.5, 3.0, 24, 8);

	glPopMatrix();
}


void Cone::update()
{
	transform.rotation.y += 0.2f;

	if (transform.rotation.y >= 360.0f)
	{
		transform.rotation.y = 0.0f;
	}
}
