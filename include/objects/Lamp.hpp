#ifndef LAMP_HPP
#define LAMP_HPP

#include "Renderable.hpp"
#include "Light.hpp"

class Lamp : public Renderable
{
private:
    float upperAngle;
    Light light;

		void drawBox( float width, float height, float depth) const;

    void drawBezierCable() const;
    void drawShade() const;

		void applyPartMaterial( float r, float g, float b, float shininess, float emission = 0.0f) const;

    Vector3 bulbLocalPosition() const;
    void syncLight();

public:
    Lamp();

    void draw() const;

    void update();
    void rotateUpperPart();

    Light &getLight();
};

#endif
