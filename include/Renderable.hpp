#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "Transform.hpp"
#include "Material.hpp"

class Renderable
{
	public:
		Transform transform;
		Material material;

		bool visible;
		bool wireframe;

		Renderable(): visible(true), wireframe(false) {}
		virtual ~Renderable() {}

		virtual void draw() const = 0;
};

#endif
