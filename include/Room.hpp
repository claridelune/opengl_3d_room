#ifndef ROOM_HPP
#define ROOM_HPP

class Room
{
	private:
		float width, height, depth;
	public:
		Room(float width, float height, float depth);

		void draw() const;

		float floorY() const;
		float backZ() const;
		float leftX() const;
		float rightX() const;
};

#endif
