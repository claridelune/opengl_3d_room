#ifndef SCENE_HPP
#define SCENE_HPP

#include "Cone.hpp"
#include "OBJModel.hpp"

class Scene
{
	private:
		Cone cone;
		OBJModel model;

	public:
		Scene();
		void draw() const;
};

#endif
