#ifndef BED_HPP
#define BED_HPP

#include "OBJModel.hpp"
#include "Transform.hpp"

class Bed
{
	private:
		OBJModel model;
	public:
		Transform transform;

		bool load();
		void draw() const;
};

#endif
