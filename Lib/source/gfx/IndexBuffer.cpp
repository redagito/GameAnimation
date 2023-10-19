#include "gfx/IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
	glGenBuffers(1, &m_bufferId);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_bufferId);
}

void IndexBuffer::set(const GLuint* data, unsigned int count)
{
	glNamedBufferData(m_bufferId, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	m_count = count;
}

void IndexBuffer::set(const std::vector<GLuint> data)
{
	set(data.data(), data.size());
}

unsigned int IndexBuffer::getCount() const
{
	return m_count;
}

GLuint IndexBuffer::getId() const
{
	return m_bufferId;
}