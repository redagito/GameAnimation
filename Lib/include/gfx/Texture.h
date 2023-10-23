#pragma once

#include <glad/glad.h>

#include <string>

class Texture
{
public:
	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;

	Texture();
	Texture(const char* path);
	Texture(const std::string& path);
	~Texture();

	void load(const char* path);
	void load(const std::string& path);

	void set(GLint uniformLocation, GLint textureIndex);
	void unset(unsigned int textureIndex);

	GLuint getId() const;

protected:
	unsigned int m_width = 0;
	unsigned int m_height = 0;
	
	// 1 - greyscale
	// 2 - ?
	// 3 - rgb
	// 4 - rgba
	unsigned int m_channels = 0;

	GLuint m_textureId = 0;

private:
};