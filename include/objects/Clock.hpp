#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "Renderable.hpp"

class Clock : public Renderable
{
private:
    float minuteAngle;

    void drawBox(
        float width,
        float height,
        float depth
    ) const;

public:
    using Renderable::transform;

    Clock();

    void draw() const;

    // Actualiza el minutero
    void update();
};

#endif
