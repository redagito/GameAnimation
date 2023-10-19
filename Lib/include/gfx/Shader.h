#pragma once

#include <unordered_map>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

	Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	~Shader();

	void bind();
	void unbind();
	GLuint getId() const;

	GLint getAttributeLocation(const std::string& name) const;
	GLint getUniformLocation(const std::string& name) const;

	// Uniforms
	void set(GLint location, const float* arrVal, unsigned int length);
	void set(GLint location, const glm::vec2* arrVal, unsigned int length);
	void set(GLint location, const glm::vec3* arrVal, unsigned int length);
	void set(GLint location, const glm::vec4* arrVal, unsigned int length);
	void set(GLint location, const glm::mat4* arrVal, unsigned int length);
	void set(GLint location, const glm::quat* arrVal, unsigned int length);
	void set(GLint location, const int* arrVal, unsigned int length);
	void set(GLint location, const glm::ivec2* arrVal, unsigned int length);
	void set(GLint location, const glm::ivec3* arrVal, unsigned int length);
	void set(GLint location, const glm::ivec4* arrVal, unsigned int length);

	// Single
	template <typename T>
	void set(GLint location, const T& value)
	{
		// As array size 1
		set(location, &value, 1);
	}

	// Multiple from vector
	template <typename T>
	void set(GLint location, const std::vector<T>& values)
	{
		set(location, values.data(), values.size());
	}

	// By name
	template <typename T>
	void set(const std::string& name, const T& value)
	{
		set(getUniformLocation(name), value);
	}

	template <typename T>
	void set(const std::string& name, const float* arrVal, unsigned int length)
	{
		set(getUniformLocation(name), arrVal, length);
	}

	template <typename T>
	void set(const std::string& name, const std::vector<float>& values)
	{
		set(getUniformLocation(name), values);
	}

private:
	static GLuint s_activeShaderId;

	GLuint m_shaderId = 0;

	// Name to location
	mutable std::unordered_map<std::string, GLint> m_attributes;
	mutable std::unordered_map<std::string, GLint> m_uniforms;

	// Reads text file into memory
	static std::string readFile(const std::string& filePath);

	// Compiles shader program files
	static GLuint compileShader(const std::string& source, GLenum shaderType);

	// Links shaders into program
	void linkShaders(GLuint vertexShaderId, GLuint fragmentShaderId);
};