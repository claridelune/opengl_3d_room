#include "Apple.hpp"
#include <GL/glut.h>
#include <cmath>

namespace
{
	const float PI = 3.14159265f;

	Vector3 point(float u, float v)
	{
		float x = std::cos(u) * (4.0f + 3.8f * std::cos(v));

		float y = std::sin(u) * (4.0f + 3.8f * std::cos(v));

		float z =
			(std::cos(v) + std::sin(v) - 1.0f) *
			(1.0f + std::sin(v)) *
			std::log(1.0f - PI * v / 10.0f) +
			7.5f * std::sin(v);

		return Vector3(x, y, z);
	}
}

Apple::Apple() : wireframe(false) {}

void Apple::toggleWireframe() { wireframe = !wireframe; }

void Apple::draw() const
{
	const int uSegments = 50;
	const int vSegments = 40;

	glPushMatrix();

	transform.apply();

	if (wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f(0.8f, 0.1f, 0.1f);

	for (int i = 0; i < vSegments; i++)
	{
		float v1 = -PI + 2.0f * PI * i / vSegments;
		float v2 = -PI + 2.0f * PI * (i + 1) / vSegments;

		glBegin(GL_QUAD_STRIP);

		for (int j = 0; j <= uSegments; j++)
		{
			float u = 2.0f * PI * j / uSegments;

			Vector3 p1 = point(u, v1);
			Vector3 p2 = point(u, v2);

			glVertex3f(p1.x, p1.y, p1.z);
			glVertex3f(p2.x, p2.y, p2.z);
		}

		glEnd();
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
}
