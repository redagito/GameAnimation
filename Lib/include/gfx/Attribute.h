#pragma once

#include <vector>
#include <glad/glad.h>

// TODO Should be called "Buffer"?
template <typename T>
class Attribute
{
public:
	Attribute(const Attribute&) = delete;
	Attribute& operator=(const Attribute&) = delete;

	Attribute();
	~Attribute();

	GLuint getId() const;
	unsigned int getCount() const;

	// Array with data and length of the array
	void set(const T* dataArray, unsigned int length);
	void set(const std::vector<T>& data);
	void bind(GLuint slot);
	void unbind(GLuint slot);

private:
	GLuint m_id = 0;
	unsigned int m_count = 0;
	void setAttribPointer(GLuint slot);
};