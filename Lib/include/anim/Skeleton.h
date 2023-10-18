#pragma once

#include <vector>
#include <string>

#include <glm/glm.hpp>

#include "anim/Pose.h"

class Skeleton
{
public:

protected:
	Pose m_restPose;
	Pose m_bindPose;

	std::vector<glm::mat4> m_invBndPose;
	std::vector<std::string> m_jointNames;
};