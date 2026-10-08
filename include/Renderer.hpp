#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Renderable.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "Light.hpp"

#include <vector>

class Renderer
{
	private:
		int maxLights;

		void drawObject(const Renderable &object) const;
		void applyMaterial(const Material &material) const;
		void applyLights(const std::vector<Light *> &lights) const;

	public:
		void initialize();
		void render(const Scene &scene, const Camera &camera) const;
};

#endif
