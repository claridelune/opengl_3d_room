#include "Plant.hpp"
#include <GL/glut.h>

Plant::Plant()
{
}

void drawLeaf()
{
    glPushMatrix();

    glScalef(
        0.18f,   // ancho
        0.70f,   // largo
        0.10f    // grosor
    );

    glutSolidSphere(1.0, 18, 18);

    glPopMatrix();
}
void Plant::draw() const
{
    // =========================
    // MACETA
    // =========================

    GLfloat potAmbient[]  = {0.18f, 0.06f, 0.02f, 1.0f};
    GLfloat potDiffuse[]  = {0.55f, 0.18f, 0.06f, 1.0f};
    GLfloat potSpecular[] = {0.55f, 0.50f, 0.45f, 1.0f};
    GLfloat potShine[]    = {22.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, potAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, potDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, potSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, potShine);

    glEnable(GL_NORMALIZE);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);

    glPushMatrix();

    // Base de la maceta
    glTranslatef(0.0f, 0.0f, 0.0f);

    // El cilindro crece sobre Z, lo rotamos para que crezca hacia arriba
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    // Parte inferior más angosta y superior más ancha
    gluCylinder(
        quad,
        0.55f,   // base inferior
        0.80f,   // parte superior
        1.0f,    // altura
        24,
        1
    );

    glPopMatrix();
    // =========================
    // SUPERIOR
    // =========================
    glPushMatrix();

    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    gluDisk(
    quad,
    0.0f,
    0.80f,
    24,
    1
    );

    glPopMatrix();

    // =========================
    // TIERRA
    // =========================

    GLfloat soilAmbient[] = {0.08f, 0.04f, 0.01f, 1.0f};
    GLfloat soilDiffuse[] = {0.20f, 0.10f, 0.03f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, soilAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, soilDiffuse);

    glPushMatrix();

    glTranslatef(0.0f, 1.05f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    gluDisk(
        quad,
        0.0f,
        0.65f,
        24,
        1
    );

    glPopMatrix();

    // =========================
    // TALLO
    // =========================

    GLfloat stemAmbient[] = {0.03f, 0.15f, 0.03f, 1.0f};
    GLfloat stemDiffuse[] = {0.10f, 0.45f, 0.10f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, stemAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, stemDiffuse);

    glPushMatrix();

    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    gluCylinder(
        quad,
        0.08f,
        0.06f,
        2.0f,
        16,
        1
    );

    glPopMatrix();

    // =========================
    // HOJAS
    // =========================

    GLfloat leafAmbient[]  = {0.05f, 0.18f, 0.05f, 1.0f};
    GLfloat leafDiffuse[]  = {0.10f, 0.70f, 0.12f, 1.0f};
    GLfloat leafSpecular[] = {0.75f, 0.75f, 0.75f, 1.0f};
    GLfloat leafShine[]    = {28.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, leafAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, leafDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, leafSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, leafShine);

    // hoja 1
    glPushMatrix();
    glTranslatef(0.35f, 2.3f, 0.0f);
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    drawLeaf();
    glPopMatrix();

    // hoja 2
    glPushMatrix();
    glTranslatef(-0.35f, 2.45f, 0.0f);
    glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
    drawLeaf();
    glPopMatrix();

    // hoja 3
    glPushMatrix();
    glTranslatef(0.25f, 2.8f, 0.1f);
    glRotatef(55.0f, 0.0f, 0.0f, 1.0f);
    drawLeaf();
    glPopMatrix();

    // hoja 4
    glPushMatrix();
    glTranslatef(-0.25f, 2.9f, -0.1f);
    glRotatef(-55.0f, 0.0f, 0.0f, 1.0f);
    drawLeaf();
    glPopMatrix();

    // hoja superior
    glPushMatrix();
    glTranslatef(0.0f, 3.2f, 0.0f);
    drawLeaf();
    glPopMatrix();

    gluDeleteQuadric(quad);
    
}