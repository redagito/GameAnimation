#include "gfx/Attribute.h"

#include <glm/glm.hpp>

template Attribute<int>;
template Attribute<float>;
template Attribute<glm::vec2>;
template Attribute<glm::vec3>;
template Attribute<glm::vec4>;
template Attribute<glm::ivec4>;

template <typename T>
Attribute<T>::Attribute()
{
	glCreateBuffers(1, &m_id);
	m_count = 0;
}

template <typename T>
Attribute<T>::~Attribute()
{
	glDeleteBuffers(1, &m_id);
}

template <typename T>
GLuint Attribute<T>::getId() const
{
	return m_id;
}

template <typename T>
unsigned int Attribute<T>::getCount() const
{
	return m_count;
}

template <typename T>
void Attribute<T>::set(const T* dataArray, unsigned int length)
{
	m_count = length;
	auto size = sizeof(T);

	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER, size * m_count, dataArray, GL_STREAM_DRAW);
	glBindBuffer(0);
}

template <typename T>
void Attribute<T>::set(const std::vector<T>& data)
{
	set(data.data(), (unsigned int)data.size());
}

void Attribute<int>::setAttribPointer(GLuint slot)
{
	glVertexAttribIPointer(slot, 1, GL_INT, 0, nullptr);
}

void Attribute<glm::ivec4>::setAttribPointer(GLuint slot)
{
	glVertexAttribIPointer(slot, 4, GL_INT, 0, nullptr);
}

void Attribute<float>::setAttribPointer(GLuint slot)
{
	glVertexAttribIPointer(slot, 1, GL_FLOAT, 0, nullptr);
}

void Attribute<glm::vec2>::setAttribPointer(GLuint slot)
{
	glVertexAttribIPointer(slot, 2, GL_FLOAT, 0, nullptr);
}

void Attribute<glm::vec3>::setAttribPointer(GLuint slot)
{
	glVertexAttribIPointer(slot, 3, GL_FLOAT, 0, nullptr);
}

void Attribute<glm::vec4>::setAttribPointer(GLuint slot)
{
	glVertexAttribIPointer(slot, 4, GL_FLOAT, 0, nullptr);
}

template <typename T>
void Attribute<T>::bind(GLuint slot)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glEnableVertexAttribArray(slot);
	setAttribPointer(slot);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

template <typename T>
void Attribute<T>::unbind(GLuint slot)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glDisableVertexAttribArray(slot);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}