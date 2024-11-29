#pragma once

#include "anim/Track.h"

// For animated transforms, contains multiple tracks
class TransformTrack
{
public:

protected:
	// Bone id
	unsigned int m_id = 0;

	VectorTrack m_position;
	QuaternionTrack m_rotation;
	VectorTrack m_scale;
};