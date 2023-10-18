#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "anim/Frame.h"
#include "anim/Interpolation.h"

template<typename T, unsigned int N>
class Track
{
public:

protected:
	std::vector<Frame<N>> m_frames;
	Interpolation m_interpolation = Interpolation::Constant;
};

using ScalarTrack = Track<float, 1>;
using VectorTrack = Track<glm::vec3, 3>;
using QuaternionTrack = Track<glm::quat, 4>;