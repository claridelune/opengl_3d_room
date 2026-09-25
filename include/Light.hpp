#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Transform.hpp"

class Light
{
	public:
		Transform transform;

		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;

		float intensity;
		bool enabled;

		Light() :
			ambient(0.1f, 0.1f, 0.1f),
			diffuse(1.0f, 1.0f, 1.0f),
			specular(1.0f, 1.0f, 1.0f),
			intensity(1.0f),
			enabled(true) { }
};

#endif
