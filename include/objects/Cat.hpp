#ifndef CAT_HPP
#define CAT_HPP

#include "OBJModel.hpp"
#include "Renderable.hpp"

class Cat : public Renderable
{
private:
    OBJModel model;

    float minX;
    float maxX;
    float speed;
    bool movingForward;
    float baseY;
    float jumpPhase;
    

    mutable unsigned int textureID;
    mutable bool textureReady;

    void createProceduralTexture() const;

public:
    Cat();

    using Renderable::transform;

    bool load();
    void update();
    void draw() const;
    void setMovementLimits(float min, float max);
    void setBaseY(float y);
};

#endif