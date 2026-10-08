#ifndef APPLE_HPP
#define APPLE_HPP

#include "Renderable.hpp"

class Apple : public Renderable
{
	public:
		void toggleWireframe();
		void draw() const;
};

#endif
