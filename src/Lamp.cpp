#include "Lamp.hpp"
#include <GL/glut.h>
#include <cmath>

const float LAMP_PI = 3.14159265f;


// ============================================================
// CONSTRUCTOR
// ============================================================

Lamp::Lamp()
    : upperAngle(0.0f)
{
}


// ============================================================
// CAJA AUXILIAR
// ============================================================

void Lamp::drawBox(
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
// ROTACION MANUAL DE LA PARTE SUPERIOR
// ============================================================

void Lamp::rotateUpperPart()
{
    upperAngle += 10.0f;

    if (upperAngle > 40.0f)
    {
        upperAngle = -40.0f;
    }
}


// ============================================================
// CURVA DE BEZIER
// ============================================================

void Lamp::drawBezierCable() const
{
    float P0[3] = {0.0f, 0.0f, 0.0f};
    float P1[3] = {0.15f, 0.20f, 0.05f};
    float P2[3] = {0.45f, -0.20f, 0.05f};
    float P3[3] = {0.65f, -0.05f, 0.0f};

    glColor3f(
        0.05f,
        0.05f,
        0.05f
    );

    glLineWidth(3.0f);

    glBegin(GL_LINE_STRIP);

    for (int i = 0; i <= 30; i++)
    {
        float t =
            static_cast<float>(i) /
            30.0f;

        float u =
            1.0f - t;

        float x =
            u * u * u * P0[0] +
            3.0f * u * u * t * P1[0] +
            3.0f * u * t * t * P2[0] +
            t * t * t * P3[0];

        float y =
            u * u * u * P0[1] +
            3.0f * u * u * t * P1[1] +
            3.0f * u * t * t * P2[1] +
            t * t * t * P3[1];

        float z =
            u * u * u * P0[2] +
            3.0f * u * u * t * P1[2] +
            3.0f * u * t * t * P2[2] +
            t * t * t * P3[2];

        glVertex3f(
            x,
            y,
            z
        );
    }

    glEnd();

    glLineWidth(1.0f);
}


// ============================================================
// PANTALLA DE LA LAMPARA
// SUPERFICIE DE REVOLUCION
// ============================================================

void Lamp::drawShade() const
{
    const int segments = 32;

    float topRadius =
        0.12f;

    float bottomRadius =
        0.28f;

    float topY =
        0.0f;

    float bottomY =
        -0.35f;

    glColor3f(
        0.90f,
        0.72f,
        0.20f
    );

    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i <= segments; i++)
    {
        float angle =
            2.0f *
            LAMP_PI *
            static_cast<float>(i) /
            static_cast<float>(segments);

        float c =
            std::cos(angle);

        float s =
            std::sin(angle);

        glVertex3f(
            topRadius * c,
            topY,
            topRadius * s
        );

        glVertex3f(
            bottomRadius * c,
            bottomY,
            bottomRadius * s
        );
    }

    glEnd();
}


// ============================================================
// DIBUJO DE LA LAMPARA
// ============================================================

void Lamp::draw() const
{
    glPushMatrix();

    // Aplicamos Transform de tu compañera
    transform.apply();


    // ========================================================
    // BASE
    // ========================================================

    glColor3f(
        0.20f,
        0.20f,
        0.20f
    );

    glPushMatrix();

        glScalef(
            0.70f,
            0.12f,
            0.70f
        );

        glutSolidSphere(
            0.40f,
            20,
            20
        );

    glPopMatrix();


    // ========================================================
    // POSTE
    // ========================================================

    glColor3f(
        0.15f,
        0.15f,
        0.15f
    );

    glPushMatrix();

        glTranslatef(
            0.0f,
            0.55f,
            0.0f
        );

        drawBox(
            0.07f,
            1.10f,
            0.07f
        );

    glPopMatrix();


    // ========================================================
    // ARTICULACION
    // ========================================================

    glColor3f(
        0.30f,
        0.30f,
        0.30f
    );

    glPushMatrix();

        glTranslatef(
            0.0f,
            1.10f,
            0.0f
        );

        glutSolidSphere(
            0.08f,
            16,
            16
        );

    glPopMatrix();


    // ========================================================
    // PARTE SUPERIOR
    // MODELADO JERARQUICO
    // ========================================================

    glPushMatrix();

        glTranslatef(
            0.0f,
            1.10f,
            0.0f
        );

        glRotatef(
            upperAngle,
            0.0f,
            0.0f,
            1.0f
        );


        // ----------------------------------------------------
        // BRAZO
        // ----------------------------------------------------

        glColor3f(
            0.15f,
            0.15f,
            0.15f
        );

        glPushMatrix();

            glTranslatef(
                0.32f,
                0.0f,
                0.0f
            );

            drawBox(
                0.65f,
                0.07f,
                0.07f
            );

        glPopMatrix();


        // ----------------------------------------------------
        // CABLE BEZIER
        // ----------------------------------------------------

        drawBezierCable();


        // ----------------------------------------------------
        // PANTALLA
        // ----------------------------------------------------

        glPushMatrix();

            glTranslatef(
                0.65f,
                -0.02f,
                0.0f
            );

            drawShade();

        glPopMatrix();


        // ----------------------------------------------------
        // BOMBILLA
        // ----------------------------------------------------

        glColor3f(
            1.0f,
            0.90f,
            0.45f
        );

        glPushMatrix();

            glTranslatef(
                0.65f,
                -0.22f,
                0.0f
            );

            glutSolidSphere(
                0.08f,
                15,
                15
            );

        glPopMatrix();

    glPopMatrix();


    glPopMatrix();
}
