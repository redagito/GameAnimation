#include "gfx/Draw.h"

#include <stdexcept>

#include <glad/glad.h>

#include "gfx/IndexBuffer.h"

static GLenum drawModeToGLEnum(DrawMode mode)
{
	switch (mode)
	{
	case DrawMode::Points: return GL_POINTS;
	case DrawMode::Lines: return GL_LINES;
	case DrawMode::LineStrip: return GL_LINE_STRIP;
	case DrawMode::LineLoop: return GL_LINE_LOOP;
	case DrawMode::Triangles: return GL_TRIANGLES;
	case DrawMode::TriangleStrip: return GL_TRIANGLE_STRIP;
	case DrawMode::TriangleFan: return GL_TRIANGLE_FAN;
	default: throw std::runtime_error("Invalid or unknown draw mode");
	}
}

void draw(const IndexBuffer& indexBuffer, DrawMode mode)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.getId());
	glDrawElements(drawModeToGLEnum(mode), indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void draw(unsigned int vertexCount, DrawMode mode)
{
	glDrawArrays(drawModeToGLEnum(mode), 0, vertexCount);
}

void drawInstanced(const IndexBuffer& indexBuffer, DrawMode mode, unsigned int instanceCount)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.getId());
	glDrawElementsInstanced(drawModeToGLEnum(mode), indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr, instanceCount);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void drawInstanced(unsigned int vertexCount, DrawMode mode, unsigned int instanceCount)
{
	glDrawArraysInstanced(drawModeToGLEnum(mode), 0, vertexCount, instanceCount);
}