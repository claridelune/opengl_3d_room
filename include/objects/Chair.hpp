#ifndef CHAIR_HPP
#define CHAIR_HPP

#include "OBJModel.hpp"
#include "Renderable.hpp"

class Chair : public Renderable
{
	private:
		OBJModel model;
	public:
		using Renderable::transform;

		bool load();
		void draw() const;
};

#endif
