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

Vector3 Transform::transformPoint( const Vector3 &point) const
{
	const float PI = 3.14159265f;

	Vector3 p( point.x * scale.x, point.y * scale.y, point.z * scale.z);

	float a = rotation.z * PI / 180.0f;
	float c = std::cos(a);
	float s = std::sin(a);
	float x = p.x * c - p.y * s;
	float y = p.x * s + p.y * c;
	p.x = x;
	p.y = y;

	a = rotation.y * PI / 180.0f;

	c = std::cos(a);
	s = std::sin(a);
	x = p.x * c + p.z * s;

	float z = -p.x * s + p.z * c;
	p.x = x;
	p.z = z;

	a = rotation.x * PI / 180.0f;

	c = std::cos(a);
	s = std::sin(a);

	y = p.y * c - p.z * s;
	z = p.y * s + p.z * c;

	p.y = y;
	p.z = z;

	p.x += position.x;
	p.y += position.y;
	p.z += position.z;

	return p;
}
