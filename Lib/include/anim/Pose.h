#pragma once

#include <vector>

#include "math/Transform.h"

class Pose
{
public:

protected:
	std::vector<Transform> m_joints;
	std::vector<int> m_parents;
};