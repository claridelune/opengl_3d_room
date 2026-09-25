#ifndef BLINDS_HPP
#define BLINDS_HPP

#include "OBJModel.hpp"
#include "Renderable.hpp"

class Blinds : public Renderable
{
	private:
		OBJModel model;
	public:
		using Renderable::transform;

		bool load();
		void draw() const;
};

#endif
