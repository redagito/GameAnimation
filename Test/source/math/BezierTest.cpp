#include <catch2/catch_test_macros.hpp>

#include <math/Bezier.h>
#include <glm/glm.hpp>

TEST_CASE("Bezier", "[bezier]")
{
	Bezier<float> bf;
	Bezier<double> bd;
	Bezier<glm::vec2> bv2;
	Bezier<glm::vec3> bv3;
	Bezier<glm::vec4> bv4;
}