#ifndef CHAIR_HPP
#define CHAIR_HPP

#include "OBJModel.hpp"
#include "Transform.hpp"

class Chair
{
	private:
		OBJModel model;
	public:
		Transform transform;

		bool load();
		void draw() const;
};

#endif
