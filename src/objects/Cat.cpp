#include "Cat.hpp"
#include <GL/glut.h>
#include <iostream>
#include <cmath>

Cat::Cat()
{
    minX = 0.0f;
    maxX = 0.0f;

    speed = 0.025f;
    movingForward = true;
    textureID = 0;
    textureReady = false;

    baseY = 0.0f;
    jumpPhase = 0.0f;
}
void Cat::setBaseY(float y)
{
    baseY = y;
}
bool Cat::load()
{
    return model.load("assets/models/cat.obj");
}

void Cat::createProceduralTexture() const
{
    const int W = 128;
    const int H = 128;

    unsigned char data[W * H * 3];

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            int index = (y * W + x) * 3;

            // Naranja base con pequeñas variaciones
            int variation = ((x * 13 + y * 7) % 25) - 12;

            int r = 225 + variation;
            int g = 105 + variation / 2;
            int b = 30;

            // Rayas blancas ligeramente irregulares
            int wave = (y / 8) % 6;

            bool whiteStripe =
                ((x + wave * 3) % 42) < 8;

            if (whiteStripe)
            {
                r = 245;
                g = 240;
                b = 225;
            }

            data[index]     = (unsigned char)r;
            data[index + 1] = (unsigned char)g;
            data[index + 2] = (unsigned char)b;
        }
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_S,
        GL_REPEAT
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        GL_REPEAT
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MAG_FILTER,
        GL_LINEAR
    );

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        W,
        H,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        data
    );

    glBindTexture(GL_TEXTURE_2D, 0);

    textureReady = true;
}

void Cat::setMovementLimits(float min, float max)
{
    minX = min;
    maxX = max;
}

void Cat::update()
{
    if (movingForward)
    {
        transform.position.x += speed;
        transform.rotation.y = 0.0f;

        if (transform.position.x >= maxX)
        {
            transform.position.x = maxX;
            movingForward = false;
        }
    }
    else
    {
        transform.position.x -= speed;
        transform.rotation.y = 180.0f;

        if (transform.position.x <= minX)
        {
            transform.position.x = minX;
            movingForward = true;
        }
    }

    // Salto
    jumpPhase += 0.08f;

    transform.position.y =
        baseY +
        0.18f * std::fabs(std::sin(jumpPhase));
}

void Cat::draw() const
{
    if (!textureReady)
    createProceduralTexture();
    // Material naranja base
    GLfloat ambient[]  = {0.25f, 0.10f, 0.02f, 1.0f};
    GLfloat diffuse[]  = {0.95f, 0.38f, 0.08f, 1.0f};
    GLfloat specular[] = {0.20f, 0.20f, 0.20f, 1.0f};
    GLfloat shininess[] = {12.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    model.draw();
}