#pragma once

// Cubic Hermite spline
template<typename T>
struct Hermite
{
	T point1;
	T slope1;

	T point2;
	T slope2;
};

template<typename T>
T interpolate(const Hermite<T>& curve, float t)
{
	return
		curve.point1 * ((1.0f + 2.0f * t) * ((1.0f - t) * (1.0f - t))) +
		curve.slope1 * (t * ((1.0f - t) * (1.0f - t))) +
		curve.point2 * ((t * t) * (3.0f - 2.0f * t)) +
		curve.slope2 * ((t * t) * (t - 1.0f));
}