#include "gfx/Shader.h"

#include <fstream>
#include <sstream>

GLuint Shader::s_activeShaderId = 0;

Shader::Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	// Load shaders
	GLuint vsId = compileShader(readFile(vertexShaderFilePath), GL_VERTEX_SHADER);
	GLuint fsId = compileShader(readFile(fragmentShaderFilePath), GL_FRAGMENT_SHADER);
	// Create and link program
	m_shaderId = glCreateProgram();
	linkShaders(vsId, fsId);
}

Shader::~Shader()
{
	if (s_activeShaderId == m_shaderId) unbind();
	glDeleteProgram(m_shaderId);
}

void Shader::Shader::bind()
{
	if (s_activeShaderId == m_shaderId) return;

	glUseProgram(m_shaderId);
	s_activeShaderId = m_shaderId;
}

void Shader::Shader::unbind()
{
	if (s_activeShaderId == 0) return;
	glUseProgram(0);
	s_activeShaderId = 0;
}

GLuint Shader::getId() const
{
	return m_shaderId;
}

GLint Shader::getAttributeLocation(const std::string& name) const
{
	// Check cache
	auto iter = m_attributes.find(name);
	if (iter != m_attributes.end()) return iter->second;
	
	// Not in cache
	GLint location = glGetAttribLocation(m_shaderId, name.c_str());
	if (location < 0) throw std::runtime_error("Invalid or unknown attribute name: " + name);

	// Update cache
	m_attributes[name] = location;
	return location;
}

GLuint Shader::getUniformLocation(const std::string& name) const
{
	// Check cache
	auto iter = m_uniforms.find(name);
	if (iter != m_uniforms.end()) return iter->second;

	// Not in cache
	GLint location = glGetUniformLocation(m_shaderId, name.c_str());
	if (location < 0) throw std::runtime_error("Invalid or unknown uniform name: " + name);

	// Update cache
	m_uniforms[name] = location;
	return location;
}

std::string Shader::readFile(const std::string& filePath)
{
	std::ifstream ifs{ filePath };
	if (!ifs.is_open()) throw std::runtime_error("Failed to read file " + filePath);
	std::stringstream ss;
	ss << ifs.rdbuf();
	ifs.close();

	return ss.str();
}

GLuint Shader::compileShader(const std::string& source, GLenum shaderType)
{
	GLuint id = glCreateShader(shaderType);
	const char* s = source.data();
	glShaderSource(id, 1, &s, nullptr);
	glCompileShader(id);

	GLint status = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &status);
	if (status == GL_TRUE) return id;

	// Error
	char infoLog[512];
	glGetShaderInfoLog(id, sizeof(infoLog), nullptr, infoLog);
	glDeleteShader(id);
	throw std::runtime_error("Failed to compile shader: " + std::string(infoLog));
}

void Shader::linkShaders(GLuint vertexShaderId, GLuint fragmentShaderId)
{
	// Link into program
	glAttachShader(m_shaderId, vertexShaderId);
	glAttachShader(m_shaderId, fragmentShaderId);
	glLinkProgram(m_shaderId);

	// Cleanup shaders
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	// Check errors
	GLint status = 0;
	glGetProgramiv(m_shaderId, GL_LINK_STATUS, &status);
	if (status == GL_TRUE) return;

	// Error
	char infoLog[512];
	glGetProgramInfoLog(m_shaderId, sizeof(infoLog), nullptr, infoLog);
	glDeleteProgram(m_shaderId);
	throw std::runtime_error("Failed to link shader: " + std::string(infoLog));
}