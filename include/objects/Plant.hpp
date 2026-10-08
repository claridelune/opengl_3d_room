#ifndef PLANT_HPP
#define PLANT_HPP

#include "Renderable.hpp"

class Plant : public Renderable
{
public:
    Plant();

    using Renderable::transform;

    void draw() const;
};

#endif