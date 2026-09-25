#ifndef SHELF_HPP
#define SHELF_HPP

#include "Renderable.hpp"

class Shelf : public Renderable
{
private:
    bool wireframe;

    void drawBox(
        float width,
        float height,
        float depth
    ) const;

public:
    using Renderable::transform;

    Shelf();

    void draw() const;

    // Cambia entre solido y wireframe
    void toggleWireframe();
};

#endif
