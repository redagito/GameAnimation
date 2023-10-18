#include "math/Transform.h"

#include <limits>

#include <glm/gtx/quaternion.hpp>

#include "util/Exceptions.h"

Transform::Transform(const glm::vec3& translation, const glm::quat& rotation, const glm::vec3& scale)
	: translation(translation), rotation(rotation), scale(scale)
{ }

Transform combine(const Transform& a, const Transform& b)
{
	Transform result;
	result.scale = a.scale * b.scale;
	result.rotation = a.rotation * b.rotation;
	// scale, rotate, transate
	result.translation = a.translation + a.rotation * (a.scale * b.translation);

	return result;
}

Transform inverse(const Transform& a)
{
	Transform result;

	// Invert scale
	if (std::abs(a.scale.x) < std::numeric_limits<float>::epsilon()) result.scale.x = 0.f;
	else result.scale.x = 1.f / a.scale.x;

	if (std::abs(a.scale.y) < std::numeric_limits<float>::epsilon()) result.scale.y = 0.f;
	else result.scale.y = 1.f / a.scale.y;

	if (std::abs(a.scale.z) < std::numeric_limits<float>::epsilon()) result.scale.z = 0.f;
	else result.scale.z = 1.f / a.scale.z;

	// Invert translation
	result.translation = a.translation * -1.f;

	// Invert rotation
	result.rotation = glm::inverse(a.rotation);

	return result;
}

Transform mix(const Transform& a, const Transform& b, float t)
{
	Transform result;

	// rotation
	glm::quat bRot = b.rotation;
	if (glm::dot(a.rotation, bRot) < 0.f)
	{
		bRot = -bRot;
	}

	result.translation = glm::mix(a.translation, b.translation, t);
	result.rotation = glm::lerp(a.rotation, bRot, t);
	result.scale = glm::mix(a.scale, b.scale, t);

	return result;
}

glm::mat4 toMat4(const Transform& t)
{
	// Extract rotation
	auto rot = glm::toMat4(t.rotation);
	auto trans = glm::translate(glm::mat4(1.f), t.translation);
	auto scale = glm::scale(glm::mat4(1.f), t.scale);

	// Matrix multiplication from left side
	// Correct order: scale, rotate, translate
	return trans * rot * scale;
}

// Based on https://stackoverflow.com/questions/17918033/glm-decompose-mat4-into-translation-and-rotation
Transform toTransform(const glm::mat4& m)
{
	Transform t;
	t.translation = m[3];
	t.scale.x = glm::length(m[0]);
	t.scale.y = glm::length(m[1]);
	t.scale.z = glm::length(m[2]);

	glm::mat3 rotationMatrix{
		glm::vec3{m[0]} / t.scale.x,
		glm::vec3{m[1]} / t.scale.y,
		glm::vec3{m[2]} / t.scale.z,
	};

	t.rotation = glm::quat_cast(rotationMatrix);

	return t;
}

glm::vec3 transformPoint(const Transform& t, const glm::vec3& point)
{
	return t.translation + t.rotation * (t.scale * point);
}

glm::vec3 transformVector(const Transform& t, const glm::vec3& vec)
{
	// Same as point, but without translation
	return t.rotation * (t.scale * vec);
}