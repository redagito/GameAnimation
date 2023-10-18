#include <catch2/catch_test_macros.hpp>

#include <app/GLApplication.h>

TEST_CASE("GLApplication", "[glapplication]")
{
	GLApplication app;
	app.initialize();
	app.update(0.03);
	app.render();
	app.shutdown();
}