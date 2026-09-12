#ifndef LAMP_HPP
#define LAMP_HPP

#include "Transform.hpp"

class Lamp
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
    Transform transform;

    Lamp();

    void draw() const;

    // Movimiento manual con teclado
    void rotateUpperPart();
};

#endif
