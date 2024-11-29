#pragma once

#include <array>

// Stores keyframes in an animation track
template<size_t N>
struct Frame
{
	std::array<float, N> time;
	std::array<float, N> value;
	// Tangents
	std::array<float, N> in;
	std::array<float, N> out;
};

using ScalarFrame = Frame<1>;
using VectorFrame = Frame<3>;
using QuaternionFrame = Frame<4>;