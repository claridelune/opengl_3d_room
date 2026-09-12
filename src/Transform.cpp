#include "Transform.hpp"
#include <GL/glut.h>

Transform::Transform(): position(0,0,0), rotation(0,0.0), scale(1,1,1) {}

void Transform::apply() const
{
	glTranslatef(position.x, position.y, position.z);

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glScalef(scale.x, scale.y, scale.z);
}
