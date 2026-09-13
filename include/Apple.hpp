#ifndef APPLE_HPP
#define APPLE_HPP

#include "Transform.hpp"

class Apple
{
	private:
		bool wireframe;
	public:
		Transform transform;
		
		Apple();

		void toggleWireframe();
		void draw() const;
};

#endif
