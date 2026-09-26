#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glut.h>
#include <string>

class Texture
{
	private:
		GLuint id;

		Texture(const Texture &);
		Texture &operator=(const Texture &);

	public:
		Texture();
		~Texture();

		bool load(const std::string &path);
		void bind() const;

		bool isLoaded() const;
};

#endif
