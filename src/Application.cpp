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

	// L: rotar parte superior de la lampara
    else if (key == 'l' || key == 'L')
    {
        scene.rotateLamp();
    }

    // V: activar / desactivar wireframe del estante
    else if (key == 'v' || key == 'V')
    {
        scene.toggleShelfWireframe();
    }

    // Movimiento de camara existente
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
