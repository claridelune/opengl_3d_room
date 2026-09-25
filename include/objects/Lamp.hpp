#ifndef LAMP_HPP
#define LAMP_HPP

#include "Renderable.hpp"

class Lamp : public Renderable
{
private:
    float upperAngle;

    void drawBox(
        float width,
        float height,
        float depth
    ) const;

    void drawShade() const;
    void drawBezierCable() const;

public:
    using Renderable::transform;

    Lamp();

    void draw() const;

    // Movimiento manual con teclado
    void rotateUpperPart();
};

#endif
