#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "Transform.hpp"

class Clock
{
private:
    float minuteAngle;

    void drawBox(
        float width,
        float height,
        float depth
    ) const;

public:
    Transform transform;

    Clock();

    void draw() const;

    // Actualiza el minutero
    void update();
};

#endif
