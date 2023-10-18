#pragma once

#include <glm/glm.hpp>

template<typename T>
struct Bezier
{
	T point1;
	T control1;

	T point2;
	T control2;
};

template<typename T>
T interpolate(const Bezier<T>& curve, float t)
{
	// Original code:
	//auto a = glm::lerp(curve.point1, curve.control1, t);
	//auto b = glm::lerp(curve.point2, curve.control2, t);
	//auto c = glm::lerp(curve.point3, curve.control3, t);
	//auto d = glm::lerp(a, c, t);
	//auto e = glm::lerp(c, b, t);
	//return glm::lerp(d, e, t);
	// 
	// Simplified:
	return curve.point1 * ((1 - t) * (1 - t) * (1 - t)) +
		curve.control1 * (3.0f * ((1 - t) * (1 - t)) * t) +
		curve.control2 * (3.0f * (1 - t) * (t * t)) +
		curve.point2 * (t * t * t);
}