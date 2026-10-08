#include "OBJModel.hpp"
#include <GL/glut.h>
#include <fstream>
#include <sstream>
#include <iostream>

bool OBJModel::load(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	vertices.clear();
	normals.clear();
	texCoords.clear();
	faces.clear();

	std::string line;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string type;
		ss >> type;

		if (type == "v") {
			Vector3 v;
			ss >> v.x >> v.y >> v.z;
			vertices.push_back(v);
		} else if (type == "vn") {
			Vector3 n;
			ss >> n.x >> n.y >> n.z;

			normals.push_back(n);
		} else if (type == "vt") {
			Vector2 t;
			ss >> t.x >> t.y;

			texCoords.push_back(t);
		} else if (type == "f") {
			std::vector<FaceVertex> faceVertices;
			std::string vertexText;

			while (ss >> vertexText)
				faceVertices.push_back(parseFaceVertex(vertexText));

			for (int i = 1; i+1<faceVertices.size(); ++i) {
				Face face;
				face.a = faceVertices[0];
        face.b = faceVertices[i];
        face.c = faceVertices[i + 1];

				faces.push_back(face);
			}
		}
	}
	return true;
}

OBJModel::FaceVertex OBJModel::parseFaceVertex(const std::string &text)
{
	FaceVertex result;

	int vertex, texture, normal = -1;
	char slash;
	std::stringstream ss(text);

	ss >> vertex;
	ss >> slash;

	if (ss.peek() != '/')
		ss >> texture;

	ss >> slash;
	ss >> normal;

	result.vertex = vertex - 1;
	result.normal = normal -1;
	result.texture = texture -1;
	return result;
}

void OBJModel::draw() const
{
	glBegin(GL_TRIANGLES);

	for (unsigned int i = 0; i < faces.size(); i++)
	{
		const Face &f = faces[i];

		const FaceVertex verticesFace[3] = { f.a, f.b, f.c };

		for (int j = 0; j < 3; j++)
		{
			Vector2 t = texCoords[verticesFace[j].texture];
			Vector3 n = normals[verticesFace[j].normal];
			Vector3 v = vertices[verticesFace[j].vertex];

			glNormal3f( n.x, n.y, n.z);
			glTexCoord2f(t.x, t.y);
			glVertex3f( v.x, v.y, v.z);
		}
	}

	glEnd();
}
