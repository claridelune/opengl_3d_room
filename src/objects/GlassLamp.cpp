#include "GlassLamp.hpp"
#include <GL/glut.h>

GlassLamp::GlassLamp()
{
}

void GlassLamp::draw() const
{
    glPushAttrib(
        GL_ENABLE_BIT |
        GL_LIGHTING_BIT |
        GL_CURRENT_BIT |
        GL_DEPTH_BUFFER_BIT
    );

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);

    // =====================================================
    // 1. BASE METÁLICA
    // =====================================================

    GLfloat baseAmbient[] =
    {
        0.12f, 0.12f, 0.12f, 1.0f
    };

    GLfloat baseDiffuse[] =
    {
        0.40f, 0.40f, 0.42f, 1.0f
    };

    GLfloat baseSpecular[] =
    {
        0.90f, 0.90f, 0.90f, 1.0f
    };

    GLfloat baseShine[] =
    {
        90.0f
    };

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_AMBIENT,
        baseAmbient
    );

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_DIFFUSE,
        baseDiffuse
    );

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_SPECULAR,
        baseSpecular
    );

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_SHININESS,
        baseShine
    );

    glPushMatrix();

    glRotatef(
        -90.0f,
        1.0f,
        0.0f,
        0.0f
    );

    gluCylinder(
        quad,
        0.40f,
        0.40f,
        0.10f,
        32,
        4
    );

    // tapa superior de la base
    glTranslatef(
        0.0f,
        0.0f,
        0.10f
    );

    gluDisk(
        quad,
        0.0f,
        0.40f,
        32,
        1
    );

    glPopMatrix();


    // =====================================================
    // 2. SOPORTE METÁLICO
    // =====================================================

    glPushMatrix();

    glTranslatef(
        0.0f,
        0.10f,
        0.0f
    );

    glRotatef(
        -90.0f,
        1.0f,
        0.0f,
        0.0f
    );

    gluCylinder(
        quad,
        0.06f,
        0.06f,
        0.45f,
        20,
        4
    );

    glPopMatrix();


    // =====================================================
    // 3. PEQUEÑO SOPORTE DE LA ESFERA
    // =====================================================

    glPushMatrix();

    glTranslatef(
        0.0f,
        0.57f,
        0.0f
    );

    glutSolidSphere(
        0.11f,
        20,
        20
    );

    glPopMatrix();


    // =====================================================
    // 4. VIDRIO SEMITRANSPARENTE
    // =====================================================

    GLfloat glassAmbient[] =
    {
        0.08f, 0.15f, 0.18f, 0.32f
    };

    GLfloat glassDiffuse[] =
    {
        0.22f, 0.65f, 0.78f, 0.32f
    };

    GLfloat glassSpecular[] =
    {
        1.00f, 1.00f, 1.00f, 0.32f
    };

    GLfloat glassShine[] =
    {
        100.0f
    };

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_AMBIENT,
        glassAmbient
    );

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_DIFFUSE,
        glassDiffuse
    );

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_SPECULAR,
        glassSpecular
    );

    glMaterialfv(
        GL_FRONT_AND_BACK,
        GL_SHININESS,
        glassShine
    );

    // Transparencia
    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    // Permite ver objetos detrás del vidrio
    glDepthMask(GL_FALSE);

    glPushMatrix();

    glTranslatef(
        0.0f,
        0.88f,
        0.0f
    );

    glutSolidSphere(
        0.36f,
        36,
        36
    );

    glPopMatrix();

    glDepthMask(GL_TRUE);

    glDisable(GL_BLEND);


    // =====================================================
    // LIMPIEZA
    // =====================================================

    gluDeleteQuadric(quad);

    glPopAttrib();
}