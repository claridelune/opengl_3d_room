#ifndef SHELF_HPP
#define SHELF_HPP

#include "Transform.hpp"

class Shelf
{
private:
    bool wireframe;

    void drawBox(
        float width,
        float height,
        float depth
    ) const;

public:
    Transform transform;

    Shelf();

    void draw() const;

    // Cambia entre solido y wireframe
    void toggleWireframe();
};

#endif
