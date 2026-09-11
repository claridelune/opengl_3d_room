#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Camera.hpp"
#include "Scene.hpp"

class Application
{
	private:
		static Application *instance;

		Camera camera;
		Scene scene;

		void display();
		void reshape(int width, int height);
		void keyboard(unsigned char key);

		static void displayCallback();
		static void reshapeCallback(int width, int height);
		static void keyboardCallback(unsigned char key, int x, int y);

	public:
		bool initialize(int argc, char **argv);
		void run();
};

#endif
