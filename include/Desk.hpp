#ifndef DESK_HPP
#define DESK_HPP

#include "OBJModel.hpp"
#include "Transform.hpp"

class Desk
{
	private:
		OBJModel model;
	public:
		Transform transform;

		bool load();
		void draw() const;
};

#endif
