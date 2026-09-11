#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera
{
	private:
		float x, y, z;
		float yaw, pitch;

	public:
		Camera();

		void apply() const;
		void move(unsigned char key);
		void reset();
};

#endif
