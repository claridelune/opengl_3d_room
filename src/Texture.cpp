#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

Texture::Texture() : id(0) { }

Texture::~Texture()
{
	if (id != 0) glDeleteTextures(1, &id);
}

bool Texture::load(const std::string &path)
{
	int width, height, channels;

	stbi_set_flip_vertically_on_load(1);
	unsigned char *data = stbi_load( path.c_str(), &width, &height, &channels, 0);

	if (!data) {
		std::cout << "Could not load texture: " << path << std::endl;
		return false;
	}

	GLenum format;

	if (channels == 4)
		format = GL_RGBA;
	else if (channels == 3)
		format = GL_RGB;
	else
	{
		stbi_image_free(data);
		return false;
	}

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D( GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
	return true;
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, id);
}

bool Texture::isLoaded() const
{
	return id != 0;
}
