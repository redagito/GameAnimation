#include <chrono>
#include <algorithm>
#include <fmtlog/fmtlog.h>

#include "app/Application.h"
#include "app/GLApplication.h"

void run(Application& app)
{
	app.initialize();

	std::chrono::milliseconds lastFrameDuration = std::chrono::milliseconds::zero();
	while (!app.shouldCLose())
	{
		auto start = std::chrono::high_resolution_clock::now();
		
		// Last frame duration in seconds
		float seconds = std::min(lastFrameDuration.count() / 1000.f, 0.04f);
		app.update(seconds);
		app.render();

		// Frame duration
		auto end = std::chrono::high_resolution_clock::now();
		lastFrameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	}
	app.shutdown();
}

int main()
{
	fmtlog::startPollingThread();
	logi("Start Game Animation Applicaton");

	try
	{
		GLApplication app;
		run(app);
	}
	catch (const std::exception& e)
	{
		loge("Uncaught exception: {}", e.what());
	}

	return 0;
}