#pragma once

#include "anim/Track.h"

class TransformTrack
{
public:

protected:
	unsigned int m_id = 0;

	VectorTrack m_position;
	QuaternionTrack m_rotation;
	VectorTrack m_scale;
};