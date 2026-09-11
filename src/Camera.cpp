#include "Camera.hpp"
#include <GL/glut.h>
#include <cmath>

static const float PI = 3.14159265f;
static const float MOVE_SPEED = 0.4f;
static const float TURN_SPEED = 5.0f;

Camera::Camera()
{
	reset();
}

void Camera::apply() const
{
	float yawRad = yaw * PI / 180.0f;
	float pitchRad = pitch * PI / 180.0f;

	float dx = std::cos(yawRad) * std::cos(pitchRad);
	float dy = std::sin(pitchRad);
	float dz = std::sin(yawRad) * std::cos(pitchRad);

	gluLookAt(x, y, z,
			x + dx, y + dy, z + dz,
			0.0f, 1.0f, 0.0f);
}

void Camera::move(unsigned char key)
{
	float angle = yaw * PI / 180.0f;
	float forwardX = std::cos(angle) * MOVE_SPEED;
	float forwardZ = std::sin(angle) * MOVE_SPEED;
	float rightX = -std::sin(angle) * MOVE_SPEED;
	float rightZ =  std::cos(angle) * MOVE_SPEED;

	switch (key)
	{
		case 'w': x += forwardX; z += forwardZ; break;
		case 's': x -= forwardX; z -= forwardZ; break;
		case 'a': x -= rightX;   z -= rightZ;   break;
		case 'd': x += rightX;   z += rightZ;   break;
		case 'q': y -= MOVE_SPEED; break;
		case 'e': y += MOVE_SPEED; break;
		case 'j': yaw -= TURN_SPEED; break;
		case 'l': yaw += TURN_SPEED; break;
		case 'i': if (pitch < 85.0f) pitch += TURN_SPEED; break;
		case 'k': if (pitch > -85.0f) pitch -= TURN_SPEED; break;
	}
}

void Camera::reset()
{
	x = 0.0f;
	y = 2.0f;
	z = 8.0f;
	yaw = -90.0f;
	pitch = -10.0f;
}
