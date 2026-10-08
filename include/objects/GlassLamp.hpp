#ifndef GLASS_LAMP_HPP
#define GLASS_LAMP_HPP

#include "Renderable.hpp"

class GlassLamp : public Renderable
{
public:
    GlassLamp();

    using Renderable::transform;

    void draw() const;
};

#endif