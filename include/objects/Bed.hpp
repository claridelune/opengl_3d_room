#ifndef BED_HPP
#define BED_HPP

#include "OBJModel.hpp"
#include "Renderable.hpp"

class Bed : public Renderable
{
	private:
		OBJModel model;
	public:
		using Renderable::transform;

		bool load();
		void draw() const;
};

#endif
