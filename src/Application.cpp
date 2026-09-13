#include "Application.hpp"
#include <GL/glut.h>
#include <cstdlib>

Application *Application::instance = 0;

bool Application::initialize(int argc, char **argv)
{
	instance = this;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);
	glutCreateWindow("3D Room");

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.00f, 1.00f, 1.0f, 1.0f);

	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutKeyboardFunc(keyboardCallback);
	glutTimerFunc(16, timerCallback, 0);

	return true;
}

void Application::run()
{
	glutMainLoop();
}

void Application::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera.apply();
	scene.draw();

	drawHelp();

	glutSwapBuffers();
}

void Application::reshape(int width, int height)
{
	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)width / height, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

void Application::keyboard(unsigned char key)
{
	if (key == 27)
		std::exit(0);

	if (key == 'r')
		camera.reset();

    else if (key == 'c' || key == 'c')
    {
        scene.rotateLamp();
    }

    else if (key == 'v' || key == 'V')
    {
        scene.toggleShelfWireframe();
    }

    else if (key == 'b' || key == 'B')
    {
        scene.toggleAppleWireframe();
    }

    else
    {
        camera.move(key);
    }

	glutPostRedisplay();
}

void Application::timer()
{
	scene.update();
	
	glutPostRedisplay();
	glutTimerFunc(16, timerCallback, 0);
}

void Application::drawText(int x, int y, const char *text)
{
	glRasterPos2i(x, y);

	while (*text)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *text++);
}

void Application::drawHelp()
{

	int width = glutGet(GLUT_WINDOW_WIDTH);
  int height = glutGet(GLUT_WINDOW_HEIGHT);

	glDisable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0, 0, 0);

	drawText(10, height - 20, "W/S - Forward / Backward");
	drawText(10, height - 40, "A/D - Left / Right");
	drawText(10, height - 60, "Q/E - Down / Up");
	drawText(10, height - 80, "I/K/J/L - Look");
	drawText(10, height - 100, "C - Rotate Lamp");
	drawText(10, height - 120, "V - Shelf Wireframe");
	drawText(10, height - 140, "B - Apple Wireframe");
	drawText(10, height - 160, "R - Reset Camera");
	drawText(10, height - 180, "ESC - Exit");

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
}

void Application::displayCallback()
{
	instance->display();
}

void Application::reshapeCallback(int width, int height)
{
	instance->reshape(width, height);
}

void Application::keyboardCallback(unsigned char key, int, int)
{
	instance->keyboard(key);
}

void Application::timerCallback(int)
{
	instance->timer();
}
