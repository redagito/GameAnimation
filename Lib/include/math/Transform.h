#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

struct Transform
{
	Transform() = default;
	Transform(const glm::vec3& translation, const glm::quat& rotation, const glm::vec3& scale);

	glm::vec3 translation = glm::vec3(0.f, 0.f, 0.f);
	glm::quat rotation = glm::quat(0.f, 0.f, 0.f, 1.f);
	glm::vec3 scale = glm::vec3(1.f);
};

Transform combine(const Transform& a, const Transform& b);
Transform inverse(const Transform& a);
Transform mix(const Transform& a, const Transform& b, float t);
glm::mat4 toMat4(const Transform& t);
// Matrix with rotation, translation and scale information (model matrix) to transform
// Assumes the matrix does NOT conatin skew or perspective information
Transform toTransform(const glm::mat4& m);
glm::vec3 transformPoint(const Transform& t, const glm::vec3& point);
glm::vec3 transformVector(const Transform& t, const glm::vec3& vec);