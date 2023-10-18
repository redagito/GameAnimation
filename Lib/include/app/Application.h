#pragma once

class Application
{
public:
	Application() = default;
	virtual ~Application() = default;

	virtual void initialize() = 0;
	// duration - last frame time
	virtual void update(float duration) = 0;
	virtual void render() = 0;
	virtual void shutdown() = 0;
	virtual bool shouldCLose() const = 0;
};