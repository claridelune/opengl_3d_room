#include "Renderer.hpp"
#include "Texture.hpp"

#include <GL/glut.h>
#include <vector>

void Renderer::initialize()
{
	glClearColor(1.00f, 1.00f, 1.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_NORMALIZE);

	glEnable(GL_LIGHTING);

	glShadeModel(GL_SMOOTH);

	glGetIntegerv( GL_MAX_LIGHTS, &maxLights);
}

void Renderer::render( const Scene &scene, const Camera &camera) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera.apply();

	applyLights(scene.getLights());

	const std::vector<Renderable *> &objects = scene.getObjects();

	for (int i = 0; i < objects.size(); i++)
		drawObject(*objects[i]);
}

void Renderer::drawObject(const Renderable &object) const
{
	if (!object.visible) return;

	glPushMatrix();

	object.transform.apply();

	applyMaterial(object.material);
	
	if (object.wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	object.draw();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glPopMatrix();
}

void Renderer::applyMaterial(const Material &material) const
{
	GLfloat ambient[] = { material.ambient.x, material.ambient.y,
		material.ambient.z, material.opacity };

	GLfloat diffuse[] = { material.diffuse.x, material.diffuse.y,
		material.diffuse.z, material.opacity };

	GLfloat specular[] = { material.specular.x, material.specular.y,
		material.specular.z, 1.0f };

	GLfloat emission[] = { material.emission.x, material.emission.y,
		material.emission.z, 1.0f };

	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, emission);
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, material.shininess);

	if (material.texture && material.texture->isLoaded())
	{
		glEnable(GL_TEXTURE_2D);
		material.texture->bind();

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	} else {
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void Renderer::applyLights( const std::vector<Light *> &lights) const
{
	for (int i = 0; i < maxLights; i++)
		glDisable(GL_LIGHT0 + i);

	int count = lights.size();

	if (count > maxLights)
		count = maxLights;

	for (int i = 0; i < count; i++)
	{
		const Light &light = *lights[i];

		if (!light.enabled)
			continue;

		GLenum id = GL_LIGHT0 + i;

		GLfloat position[] = { light.transform.position.x,
			light.transform.position.y, light.transform.position.z, 1.0f };

		GLfloat ambient[] = { light.ambient.x * light.intensity, light.ambient.y *
			light.intensity, light.ambient.z * light.intensity, 1.0f };

		GLfloat diffuse[] = { light.diffuse.x * light.intensity, light.diffuse.y *
			light.intensity, light.diffuse.z * light.intensity, 1.0f };

		GLfloat specular[] = { light.specular.x * light.intensity, light.specular.y
			* light.intensity, light.specular.z * light.intensity, 1.0f };

		glEnable(id);
		glLightfv( id, GL_POSITION, position);
		glLightfv( id, GL_AMBIENT, ambient);
		glLightfv( id, GL_DIFFUSE, diffuse);
		glLightfv( id, GL_SPECULAR, specular);
	}
}
