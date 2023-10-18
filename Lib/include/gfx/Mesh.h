#pragma once

#include <vector>

#include <glm/glm.hpp>

class Mesh
{
public:

protected:
	std::vector<glm::vec3> m_positions; // Vertices
	std::vector<glm::vec3> m_normals;
	std::vector<glm::vec2> m_texCoords;
	std::vector<glm::vec4> m_weights;
	std::vector<glm::ivec4> m_influences;
	std::vector<unsigned int> m_indices;
};