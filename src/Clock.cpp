#include "Clock.hpp"
#include <GL/glut.h>
#include <cmath>

const float CLOCK_PI = 3.14159265f;


// ============================================================
// CONSTRUCTOR
// ============================================================

Clock::Clock()
    : minuteAngle(0.0f)
{
}


// ============================================================
// FUNCION AUXILIAR
// ============================================================

void Clock::drawBox(
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
// UPDATE DEL MINUTERO
// ============================================================

void Clock::update()
{
    // Giro horario
    minuteAngle -= 0.10f;

    if (minuteAngle <= -360.0f)
    {
        minuteAngle += 360.0f;
    }
}


// ============================================================
// DIBUJO DEL RELOJ
// ============================================================

void Clock::draw() const
{
    glPushMatrix();

    // Transform general del reloj
    transform.apply();


    // ========================================================
    // CARA DEL RELOJ
    // ========================================================

    glColor3f(
        0.92f,
        0.92f,
        0.86f
    );

    glBegin(GL_POLYGON);

    for (int i = 0; i < 40; i++)
    {
        float angle =
            2.0f *
            CLOCK_PI *
            static_cast<float>(i) /
            40.0f;

        glVertex3f(
            0.48f * std::cos(angle),
            0.48f * std::sin(angle),
            0.0f
        );
    }

    glEnd();


    // ========================================================
    // MARCO
    // ========================================================

    glColor3f(
        0.18f,
        0.18f,
        0.18f
    );

    glPushMatrix();

        glutSolidTorus(
            0.045f,
            0.48f,
            16,
            32
        );

    glPopMatrix();


    // ========================================================
    // MARCAS HORARIAS
    // ========================================================

    glColor3f(
        0.10f,
        0.10f,
        0.10f
    );

    for (int i = 0; i < 12; i++)
    {
        float angle =
            i *
            30.0f *
            CLOCK_PI /
            180.0f;

        float x =
            std::sin(angle) *
            0.39f;

        float y =
            std::cos(angle) *
            0.39f;

        glPushMatrix();

            glTranslatef(
                x,
                y,
                0.035f
            );

            glRotatef(
                -i * 30.0f,
                0.0f,
                0.0f,
                1.0f
            );

            drawBox(
                0.025f,
                0.08f,
                0.025f
            );

        glPopMatrix();
    }


    // ========================================================
    // AGUJA HORARIA
    // ========================================================

    glColor3f(
        0.15f,
        0.15f,
        0.15f
    );

    glPushMatrix();

        glTranslatef(
            0.0f,
            0.11f,
            0.06f
        );

        drawBox(
            0.035f,
            0.22f,
            0.025f
        );

    glPopMatrix();


    // ========================================================
    // MINUTERO
    // ========================================================

    glPushMatrix();

        // Solo gira el minutero
        glRotatef(
            minuteAngle,
            0.0f,
            0.0f,
            1.0f
        );

        glColor3f(
            0.05f,
            0.05f,
            0.05f
        );

        glTranslatef(
            0.0f,
            0.18f,
            0.08f
        );

        drawBox(
            0.022f,
            0.36f,
            0.022f
        );

    glPopMatrix();


    // ========================================================
    // CENTRO DEL RELOJ
    // ========================================================

    glColor3f(
        0.75f,
        0.10f,
        0.08f
    );

    glPushMatrix();

        glTranslatef(
            0.0f,
            0.0f,
            0.10f
        );

        glutSolidSphere(
            0.045f,
            16,
            16
        );

    glPopMatrix();


    glPopMatrix();
}
