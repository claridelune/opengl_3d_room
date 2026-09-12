#include "Dresser.hpp"
#include <GL/glut.h>

Dresser::Dresser()
{
}

// ============================================================
// FUNCION AUXILIAR
// ============================================================

void Dresser::drawBox(
    float width,
    float height,
    float depth
) const
{
    glPushMatrix();

        glScalef(
            width,
            height,
            depth
        );

        glutSolidCube(1.0f);

    glPopMatrix();
}

// ============================================================
// DIBUJO DE LA COMODA
// ============================================================

void Dresser::draw() const
{
    glPushMatrix();

    // Aplicando la clase Transform
    transform.apply();


    // ========================================================
    // CUERPO PRINCIPAL
    // ========================================================

    glColor3f(
        0.50f,
        0.28f,
        0.12f
    );

    glPushMatrix();

        glTranslatef(
            0.0f,
            0.60f,
            0.0f
        );

        drawBox(
            1.50f,
            1.20f,
            0.60f
        );

    glPopMatrix();


    // ========================================================
    // TABLERO SUPERIOR
    // ========================================================

    glColor3f(
        0.65f,
        0.38f,
        0.16f
    );

    glPushMatrix();

        glTranslatef(
            0.0f,
            1.22f,
            0.0f
        );

        drawBox(
            1.60f,
            0.08f,
            0.68f
        );

    glPopMatrix();


    // ========================================================
    // CAJONES
    // ========================================================

    for (int i = 0; i < 3; i++)
    {
        float y =
            0.30f +
            i * 0.34f;


        glColor3f(
            0.62f,
            0.34f,
            0.14f
        );

        glPushMatrix();

            glTranslatef(
                0.0f,
                y,
                0.31f
            );

            drawBox(
                1.25f,
                0.24f,
                0.05f
            );

        glPopMatrix();


        // Tirador izquierdo

        glColor3f(
            0.85f,
            0.70f,
            0.20f
        );

        glPushMatrix();

            glTranslatef(
                -0.22f,
                y,
                0.36f
            );

            glutSolidSphere(
                0.035f,
                12,
                12
            );

        glPopMatrix();


        // Tirador derecho

        glPushMatrix();

            glTranslatef(
                0.22f,
                y,
                0.36f
            );

            glutSolidSphere(
                0.035f,
                12,
                12
            );

        glPopMatrix();
    }


    // ========================================================
    // PATAS
    // ========================================================

    glColor3f(
        0.35f,
        0.18f,
        0.08f
    );


    float legX[4] =
    {
        -0.63f,
         0.63f,
        -0.63f,
         0.63f
    };


    float legZ[4] =
    {
        -0.22f,
        -0.22f,
         0.22f,
         0.22f
    };


    for (int i = 0; i < 4; i++)
    {
        glPushMatrix();

            glTranslatef(
                legX[i],
                0.10f,
                legZ[i]
            );

            drawBox(
                0.08f,
                0.20f,
                0.08f
            );

        glPopMatrix();
    }


    glPopMatrix();
}
