#ifndef DRESSER_HPP
#define DRESSER_HPP

#include "Renderable.hpp"

class Dresser : public Renderable
{
public:
    using Renderable::transform;

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
