#pragma once

#include <vector>

#include "math/Transform.h"

// Forward And Backward Reaching Inverse Kinematic
class FABRIKSolver
{
protected:
	std::vector<Transform> m_ikChain;
	unsigned int m_numSteps = 15;
	float m_threashold = 0.00001f;
};