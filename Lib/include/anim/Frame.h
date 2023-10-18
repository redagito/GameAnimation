#pragma once

// Stores keyframes in an animation track
template<unsigned int N>
struct Frame
{
	float value[N];
	float in[N];
	float out[N];
	float time[N];
};

using ScalarFrame = Frame<1>;
using VectorFrame = Frame<3>;
using QuaternionFrame = Frame<4>;