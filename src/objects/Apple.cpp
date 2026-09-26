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

	Vector3 normal(float u, float v)
	{
		const float e = 0.001f;

		Vector3 du = point(u+e, v) - point(u-e,v);
		Vector3 dv = point(u, v+e) - point(u,v-e);

		return Vector3::cross(du, dv).normalized();
	}
}

void Apple::toggleWireframe() { wireframe = !wireframe; }

void Apple::draw() const
{
	const int uSegments = 50;
	const int vSegments = 40;

	for (int i = 0; i < vSegments; i++)
	{
		float v1 = -PI + 2.0f * PI * i / vSegments;
		float v2 = -PI + 2.0f * PI * (i + 1) / vSegments;

		float t1 = (float)i / vSegments;
		float t2 = (float)(i + 1) / vSegments;

		glBegin(GL_QUAD_STRIP);

		for (int j = 0; j <= uSegments; j++)
		{
			float u = 2.0f * PI * j / uSegments;
			float s = (float)j / uSegments;

			Vector3 p1 = point(u, v1);
			Vector3 p2 = point(u, v2);

			Vector3 n1 = normal(u, v1);
			Vector3 n2 = normal(u, v2);

			glNormal3f(n1.x, n1.y, n1.z);
			glTexCoord2f(s, t1);
			glVertex3f(p1.x, p1.y, p1.z);

			glNormal3f(n2.x, n2.y, n2.z);
			glTexCoord2f(s, t2);
			glVertex3f(p2.x, p2.y, p2.z);
		}

		glEnd();
	}
}
