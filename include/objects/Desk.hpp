#ifndef DESK_HPP
#define DESK_HPP

#include "OBJModel.hpp"
#include "Renderable.hpp"

class Desk : public Renderable
{
	private:
		OBJModel model;
	public:
		using Renderable::transform;

		bool load();
		void draw() const;
};

#endif
