#include "OBJModel.hpp"
#include <GL/glut.h>
#include <fstream>
#include <sstream>

bool OBJModel::load(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	vertices.clear();
	faces.clear();

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string type;
		ss >> type;

		if (type == "v")
		{
			Vertex v;
			ss >> v.x >> v.y >> v.z;
			vertices.push_back(v);
		}
		else if (type == "f")
		{
			Face f;
			ss >> f.a >> f.b >> f.c;
			--f.a; --f.b; --f.c;
			faces.push_back(f);
		}
	}

	return true;
}

void OBJModel::draw() const
{
	glPushMatrix();

	transform.apply();

	glBegin(GL_TRIANGLES);

	for (std::size_t i = 0; i < faces.size(); ++i)
	{
		const Face &f = faces[i];
		const Vertex &a = vertices[f.a];
		const Vertex &b = vertices[f.b];
		const Vertex &c = vertices[f.c];

		glVertex3f(a.x, a.y, a.z);
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(c.x, c.y, c.z);
	}

	glEnd();

	glPopMatrix();
}
