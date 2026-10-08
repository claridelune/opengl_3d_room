#ifndef ROOM_HPP
#define ROOM_HPP

#include "Renderable.hpp"

class Room : public Renderable
{
	private:
		float width, height, depth;
	public:
		Room(float width, float height, float depth);

		using Renderable::transform;

		void draw() const;

		float floorY() const;
		float backZ() const;
		float leftX() const;
		float rightX() const;
};

#endif
