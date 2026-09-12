#ifndef OBJ_MODEL_HPP
#define OBJ_MODEL_HPP

#include <string>
#include <vector>

#include "Transform.hpp"

class OBJModel
{
	private:
		struct Vertex { float x, y, z; };
		struct Face { int a, b, c; };

		std::vector<Vertex> vertices;
		std::vector<Face> faces;

	public:
		Transform transform;

		bool load(const std::string &filename);
		void draw() const;
};

#endif
