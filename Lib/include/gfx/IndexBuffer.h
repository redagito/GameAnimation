#pragma once

#include <vector>

#include <glad/glad.h>

// For rendering indexed geometry
class IndexBuffer
{
public:
	IndexBuffer(const IndexBuffer&) = delete;
	IndexBuffer& operator=(const IndexBuffer&) = delete;

	IndexBuffer();
	~IndexBuffer();
	void set(const GLuint* data, unsigned int count);
	void set(const std::vector<GLuint> data);

	unsigned int getCount() const;
	GLuint getId() const;

private:
	GLuint m_bufferId = 0;
	unsigned int m_count = 0;
};