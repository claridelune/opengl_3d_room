#include "Lamp.hpp"

#include <GL/glut.h>
#include <cmath>

namespace
{
	const float PI = 3.14159265f;
}

Lamp::Lamp()
	: upperAngle(0.0f)
{
	light.ambient = Vector3(0.03f, 0.02f, 0.01f);

	light.diffuse = Vector3(1.0f, 0.80f, 0.40f);

	light.specular = Vector3(1.0f, 0.90f, 0.60f);

	light.intensity = 1.0f;
}


// ============================================================
// MATERIAL AUXILIAR
// ============================================================

void Lamp::applyPartMaterial(
		float r,
		float g,
		float b,
		float shininess, float emission) const { GLfloat ambient[] = { r * 0.2f, g *
	0.2f, b * 0.2f, 1.0f };

GLfloat diffuse[] = { r, g, b, 1.0f };

GLfloat specular[] = { 0.6f, 0.6f, 0.6f, 1.0f };

GLfloat emitted[] = { r * emission, g * emission, b * emission, 1.0f };

glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);

glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specular);

glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, emitted);

glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, shininess); }


// ============================================================
// CAJA
// ============================================================

void Lamp::drawBox(
		float width,
		float height,
		float depth) const
{
	glPushMatrix();

	glScalef(
			width,
			height,
			depth
			);

	glutSolidCube(1.0f);

	glPopMatrix();
}


// ============================================================
// ROTACION
// ============================================================

void Lamp::rotateUpperPart()
{
	upperAngle += 10.0f;

	if (upperAngle > 40.0f)
		upperAngle = -40.0f;

	syncLight();
}


// ============================================================
// CABLE BEZIER
// ============================================================

void Lamp::drawBezierCable() const
{
	float p0[3] = {0.0f, 0.0f, 0.0f};
	float p1[3] = {0.15f, 0.20f, 0.05f};
	float p2[3] = {0.45f, -0.20f, 0.05f};
	float p3[3] = {0.65f, -0.05f, 0.0f};

	GLboolean lighting =
		glIsEnabled(GL_LIGHTING);

	if (lighting)
		glDisable(GL_LIGHTING);

	glColor3f(
			0.05f,
			0.05f,
			0.05f
			);

	glLineWidth(3.0f);

	glBegin(GL_LINE_STRIP);

	for (int i = 0; i <= 30; i++)
	{
		float t =
			(float)i / 30.0f;

		float u =
			1.0f - t;

		float x =
			u * u * u * p0[0] +
			3.0f * u * u * t * p1[0] +
			3.0f * u * t * t * p2[0] +
			t * t * t * p3[0];

		float y =
			u * u * u * p0[1] +
			3.0f * u * u * t * p1[1] +
			3.0f * u * t * t * p2[1] +
			t * t * t * p3[1];

		float z =
			u * u * u * p0[2] +
			3.0f * u * u * t * p1[2] +
			3.0f * u * t * t * p2[2] +
			t * t * t * p3[2];

		glVertex3f(x, y, z);
	}

	glEnd();

	glLineWidth(1.0f);

	if (lighting)
		glEnable(GL_LIGHTING);
}


// ============================================================
// PANTALLA
// ============================================================

void Lamp::drawShade() const
{
	const int segments = 32;

	const float topRadius = 0.12f;
	const float bottomRadius = 0.28f;

	const float topY = 0.0f;
	const float bottomY = -0.35f;

	float slope =
		(bottomRadius - topRadius) /
		(topY - bottomY);

	glBegin(GL_QUAD_STRIP);

	for (int i = 0; i <= segments; i++)
	{
		float angle =
			2.0f * PI * i / segments;

		float c = std::cos(angle);
		float s = std::sin(angle);

		float nx = c;
		float ny = slope;
		float nz = s;

		float length = std::sqrt( nx * nx + ny * ny + nz * nz);

		nx /= length;
		ny /= length;
		nz /= length;

		glNormal3f(nx, ny, nz);

		glVertex3f(
				topRadius * c,
				topY,
				topRadius * s
				);

		glNormal3f(nx, ny, nz);

		glVertex3f(
				bottomRadius * c,
				bottomY,
				bottomRadius * s
				);
	}

	glEnd();
}


// ============================================================
// POSICION LOCAL DE LA BOMBILLA
// ============================================================

Vector3 Lamp::bulbLocalPosition() const
{
	float angle =
		upperAngle * PI / 180.0f;

	float c = std::cos(angle); float s = std::sin(angle);

	float x = 0.65f; float y = -0.22f;

	return Vector3( c * x - s * y, 1.10f + s * x + c * y, 0.0f);
}


// ============================================================
// SINCRONIZAR LUZ
// ============================================================

void Lamp::syncLight()
{
	light.transform.position =
		transform.transformPoint(
				bulbLocalPosition()
				);
}

void Lamp::update()
{
	syncLight();
}

Light &Lamp::getLight()
{
	return light;
}


// ============================================================
// DIBUJO
// ============================================================

void Lamp::draw() const
{
	// Base

	applyPartMaterial( 0.20f, 0.20f, 0.20f, 60.0f);

	glPushMatrix();

	glScalef( 0.70f, 0.12f, 0.70f);

	glutSolidSphere( 0.40f, 20, 20);

	glPopMatrix();


	// Post

	applyPartMaterial( 0.15f, 0.15f, 0.15f, 80.0f);

	glPushMatrix();

	glTranslatef( 0.0f, 0.55f, 0.0f);

	drawBox( 0.07f, 1.10f, 0.07f);

	glPopMatrix();


	// Joint

	applyPartMaterial( 0.30f, 0.30f, 0.30f, 80.0f);

	glPushMatrix();

	glTranslatef( 0.0f, 1.10f, 0.0f);

	glutSolidSphere( 0.08f, 16, 16);

	glPopMatrix();


	// Upper hierarchical part

	glPushMatrix();

	glTranslatef( 0.0f, 1.10f, 0.0f);

	glRotatef( upperAngle, 0.0f, 0.0f, 1.0f);


	// Arm

	applyPartMaterial(
			0.15f,
			0.15f,
			0.15f,
			80.0f
			);

	glPushMatrix();

	glTranslatef( 0.32f, 0.0f, 0.0f);

	drawBox( 0.65f, 0.07f, 0.07f);

	glPopMatrix();


	// Cable

	drawBezierCable();


	// Shade

	applyPartMaterial( 0.90f, 0.72f, 0.20f, 30.0f, 0.05f);

	glPushMatrix();

	glTranslatef( 0.65f, -0.02f, 0.0f);

	drawShade();

	glPopMatrix();


	// Bulb

	applyPartMaterial( 1.0f, 0.90f, 0.45f, 100.0f, 0.85f);

	glPushMatrix();

	glTranslatef( 0.65f, -0.22f, 0.0f);

	glutSolidSphere( 0.08f, 15, 15);

	glPopMatrix();

	glPopMatrix();
}
