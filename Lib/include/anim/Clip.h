#pragma once

#include <vector>
#include <string>

#include "anim/TransformTrack.h"

class Clip
{
public:

protected:
	std::vector<TransformTrack> m_tracks;
	std::string m_name;
	float m_startTime = 0.f;
	float m_endTime = 0.f;
	bool m_looping;
};