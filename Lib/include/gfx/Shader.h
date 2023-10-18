#pragma once

#include <unordered_map>
#include <string>

#include <glad/glad.h>

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
	GLuint getUniformLocation(const std::string& name) const;
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