#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

struct Vector3
{
	float x, y, z;
	Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
};

class Transform
{
	public:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Transform();
		void apply() const;
};

#endif
