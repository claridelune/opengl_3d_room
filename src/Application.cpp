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
	glClearColor(0.08f, 0.08f, 0.10f, 1.0f);

	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutKeyboardFunc(keyboardCallback);

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
	else
		camera.move(key);

	glutPostRedisplay();
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
