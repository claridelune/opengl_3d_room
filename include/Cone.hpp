#ifndef CONE_HPP
#define CONE_HPP

#include "Transform.hpp"

class Cone
{
	public:
		Transform transform;

		void draw() const;
		void update();
};

#endif
