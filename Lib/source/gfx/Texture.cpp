#include "gfx/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <stdexcept>

Texture::Texture()
{
	glGenTextures(1, &m_textureId);
}

Texture::Texture(const char* path)
	: Texture()
{
	load(path);
}

Texture::Texture(const std::string& path)
	: Texture(path.c_str())
{ }

Texture::~Texture()
{
	glDeleteTextures(1, &m_textureId);
}

void Texture::load(const char* path)
{
	int width = 0;
	int height = 0;
	int channels = 0;
	unsigned char* data = stbi_load(path, &width, &height, &channels, 4);
	if (data == nullptr) throw std::runtime_error("Failed to load image from file " + std::string(path));

	// TODO use direct state access instead
	glBindTexture(GL_TEXTURE_2D, m_textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	m_width = (unsigned int)width;
	m_height = (unsigned int)height;
	m_channels = (unsigned int)channels;
}

void Texture::load(const std::string& path)
{
	load(path.c_str());
}

void Texture::set(GLint uniformLocation, GLint textureIndex)
{
	glActiveTexture(GL_TEXTURE0 + textureIndex);
	glBindTexture(GL_TEXTURE_2D, m_textureId);
	glUniform1i(uniformLocation, textureIndex);
}

void Texture::unset(unsigned int textureIndex)
{
	glActiveTexture(GL_TEXTURE0 + textureIndex);
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(GL_TEXTURE0);
}

GLuint Texture::getId() const
{
	return m_textureId;
}