#include "Room.hpp"
#include <GL/glut.h>

Room::Room(float width, float height, float depth) : width(width), height(height), depth(depth) { }

float Room::floorY() const { return 0.0f; }

float Room::backZ() const { return -depth; }

float Room::leftX() const { return -width / 2.0f; }

float Room::rightX() const { return width / 2.0f; }

void Room::draw() const
{
    float left = leftX();
    float right = rightX();
    float back = backZ();

    // Floor
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_QUADS);
    glVertex3f(left, 0, 0);
    glVertex3f(right, 0, 0);
    glVertex3f(right, 0, back);
    glVertex3f(left, 0, back);
    glEnd();

    // Back wall
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_QUADS);
    glVertex3f(left, 0, back);
    glVertex3f(right, 0, back);
    glVertex3f(right, height, back);
    glVertex3f(left, height, back);
    glEnd();

    // Left wall
    glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex3f(left, 0, 0);
    glVertex3f(left, 0, back);
    glVertex3f(left, height, back);
    glVertex3f(left, height, 0);
    glEnd();

    // Right wall
    glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex3f(right, 0, back);
    glVertex3f(right, 0, 0);
    glVertex3f(right, height, 0);
    glVertex3f(right, height, back);
    glEnd();
}
