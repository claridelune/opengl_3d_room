#ifndef OBJ_MODEL_HPP
#define OBJ_MODEL_HPP

#include <string>
#include <vector>

#include "Transform.hpp"

class OBJModel
{
	private:
		struct FaceVertex { int vertex, normal; };
		struct Face { FaceVertex a, b, c; };

		std::vector<Vector3> vertices;
		std::vector<Vector3> normals;
		std::vector<Face> faces;

		FaceVertex parseFaceVertex(const std::string &text);

	public:
		Transform transform;

		bool load(const std::string &filename);
		void draw() const;
};

#endif
