#ifndef BLINDS_HPP
#define BLINDS_HPP

#include "OBJModel.hpp"
#include "Transform.hpp"

class Blinds
{
	private:
		OBJModel model;
	public:
		Transform transform;

		bool load();
		void draw() const;
};

#endif
