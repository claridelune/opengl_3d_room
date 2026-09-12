#include "Shelf.hpp"
#include <GL/glut.h>


Shelf::Shelf()
    : wireframe(false)
{
}


// ============================================================
// FUNCION AUXILIAR
// ============================================================

void Shelf::drawBox(
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

        if (wireframe)
        {
            glutWireCube(1.0f);
        }
        else
        {
            glutSolidCube(1.0f);
        }

    glPopMatrix();
}


// ============================================================
// CAMBIAR MODO WIREFRAME
// ============================================================

void Shelf::toggleWireframe()
{
    wireframe = !wireframe;
}


// ============================================================
// DIBUJAR ESTANTE
// ============================================================

void Shelf::draw() const
{
    glPushMatrix();

    // Transform general del objeto
    transform.apply();


    // ========================================================
    // COLOR GENERAL
    // ========================================================

    glColor3f(
        0.48f,
        0.26f,
        0.10f
    );


    // ========================================================
    // LATERAL IZQUIERDO
    // ========================================================

    glPushMatrix();

        glTranslatef(
            -0.50f,
            0.90f,
            0.0f
        );

        drawBox(
            0.10f,
            1.80f,
            0.40f
        );

    glPopMatrix();


    // ========================================================
    // LATERAL DERECHO
    // ========================================================

    glPushMatrix();

        glTranslatef(
            0.50f,
            0.90f,
            0.0f
        );

        drawBox(
            0.10f,
            1.80f,
            0.40f
        );

    glPopMatrix();


    // ========================================================
    // REPISAS
    // ========================================================

    for (int i = 0; i < 5; i++)
    {
        float y =
            0.05f +
            i * 0.42f;


        glPushMatrix();

            glTranslatef(
                0.0f,
                y,
                0.0f
            );

            drawBox(
                1.00f,
                0.08f,
                0.40f
            );

        glPopMatrix();
    }


    // ========================================================
    // LIBROS
    //
    // Solo cuando no esta en wireframe
    // ========================================================

    if (!wireframe)
    {
        // Libro rojo

        glColor3f(
            0.70f,
            0.15f,
            0.10f
        );

        glPushMatrix();

            glTranslatef(
                -0.28f,
                0.23f,
                0.0f
            );

            glScalef(
                0.10f,
                0.28f,
                0.25f
            );

            glutSolidCube(1.0f);

        glPopMatrix();


        // Libro azul

        glColor3f(
            0.10f,
            0.30f,
            0.70f
        );

        glPushMatrix();

            glTranslatef(
                -0.15f,
                0.23f,
                0.0f
            );

            glScalef(
                0.08f,
                0.28f,
                0.25f
            );

            glutSolidCube(1.0f);

        glPopMatrix();


        // Libro verde

        glColor3f(
            0.15f,
            0.55f,
            0.20f
        );

        glPushMatrix();

            glTranslatef(
                -0.03f,
                0.23f,
                0.0f
            );

            glScalef(
                0.10f,
                0.28f,
                0.25f
            );

            glutSolidCube(1.0f);

        glPopMatrix();
    }


    glPopMatrix();
}
