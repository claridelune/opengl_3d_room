#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Transform.hpp"

class Material
{
	public:
		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;
		Vector3 emission;

		float shininess;
		float opacity;

		Material() :
			ambient(0.2f, 0.2f, 0.2f),
			diffuse(1.0f, 1.0f, 1.0f),
			specular(0.0f, 0.0f, 0.0f),
			emission(0.0f, 0.0f, 0.0f),
			shininess(0.0f), 
			opacity(1.0f) { }
};

#endif
