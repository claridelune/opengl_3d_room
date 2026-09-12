#ifndef DRESSER_HPP
#define DRESSER_HPP

#include "Transform.hpp"

class Dresser
{
public:
    Transform transform;

    Dresser();

    void draw() const;

private:
    void drawBox(
        float width,
        float height,
        float depth
    ) const;
};

#endif
