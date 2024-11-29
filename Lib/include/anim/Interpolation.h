#pragma once

// Possible interpolation types
enum class Interpolation
{
    // Keeps value the same until next keyframe, also called step-curve
    Constant,
    // Linearly interpolates between two frames
    Linear,
    // Interpolates using cubic equations
    Cubic
};