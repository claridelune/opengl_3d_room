#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <cmath>

struct Vector3
{
	float x, y, z;
	Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

	Vector3 operator-(const Vector3 &v) const
	{ return Vector3( x - v.x, y - v.y, z - v.z); }

	float length() const
	{ return sqrt( x * x + y * y + z * z); }

	Vector3 normalized() const
	{
		float l = length();

		if (l == 0) return Vector3();

		return Vector3( x/l, y/l, z/l);
	}

	static Vector3 cross( const Vector3 &a, const Vector3 &b)
	{
		return Vector3(
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x
				);
	}
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
