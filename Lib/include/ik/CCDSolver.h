#pragma once

#include <vector>

#include "math/Transform.h"

// Cyclic Coordinate Descent IK solver
class CCDSolver
{
public:
	CCDSolver() = default;

protected:
	std::vector<Transform> m_ikChain;
	unsigned int m_numSteps = 15;
	float m_threshold = 0.00001f;
};