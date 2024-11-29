#include "anim/Track.h"

template Track<float, 1>;
template Track<glm::vec3, 3>;
template Track<glm::quat, 4>;

void setSize(size_t size);
size_t getSize() const;

Interpolation getInterpolation() const;
void setInterpolation(Interpolation interpolation);

float getStartTime() const;
float getEndTime() const;

// Sample the track at time
T sample(float time, bool looping);