#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "anim/Frame.h"
#include "anim/Interpolation.h"

// Collection of frames
// Must have at least 2 frames for interpolation
template<typename T, size_t N>
class Track
{
public:
	Track() = default;

	void setSize(size_t size);
	size_t getSize() const;

	Interpolation getInterpolation() const;
	void setInterpolation(Interpolation interpolation);

	float getStartTime() const;
	float getEndTime() const;

	// Sample the track at time
	T sample(float time, bool looping);

protected:
	std::vector<Frame<N>> m_frames;
	Interpolation m_interpolation = Interpolation::Constant;
};

using ScalarTrack = Track<float, 1>;
using VectorTrack = Track<glm::vec3, 3>;
using QuaternionTrack = Track<glm::quat, 4>;