#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <math/Transform.h>

TEST_CASE("Transform to and from mat4", "[transform]")
{
	constexpr float epsilon = 0.000001f;

	glm::vec3 translation{ 1.0f, 2.0f, 3.0f };
	glm::vec3 eulerAngles{ 0.3f, 0.2f, 0.5f };
	glm::quat rotation{ eulerAngles };
	glm::vec3 scale{ 10.f, 12.f, 15.f };

	Transform trans{ translation, rotation, scale };
	auto modelMatrix = toMat4(trans);
	Transform trans2 = toTransform(modelMatrix);

	REQUIRE_THAT(trans2.rotation.x, Catch::Matchers::WithinRel(trans.rotation.x, epsilon));
	REQUIRE_THAT(trans2.rotation.y, Catch::Matchers::WithinRel(trans.rotation.y, epsilon));
	REQUIRE_THAT(trans2.rotation.z, Catch::Matchers::WithinRel(trans.rotation.z, epsilon));
	REQUIRE_THAT(trans2.rotation.w, Catch::Matchers::WithinRel(trans.rotation.w, epsilon));

	REQUIRE_THAT(trans2.translation.x, Catch::Matchers::WithinRel(trans.translation.x, epsilon));
	REQUIRE_THAT(trans2.translation.y, Catch::Matchers::WithinRel(trans.translation.y, epsilon));
	REQUIRE_THAT(trans2.translation.z, Catch::Matchers::WithinRel(trans.translation.z, epsilon));

	REQUIRE_THAT(trans2.scale.x, Catch::Matchers::WithinRel(trans.scale.x, epsilon));
	REQUIRE_THAT(trans2.scale.y, Catch::Matchers::WithinRel(trans.scale.y, epsilon));
	REQUIRE_THAT(trans2.scale.z, Catch::Matchers::WithinRel(trans.scale.z, epsilon));
}