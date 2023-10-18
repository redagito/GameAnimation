#pragma once

#include "Application.h"

class GLFWwindow;

class GLApplication : public Application
{
private:
	GLFWwindow* m_window = nullptr;

public:
	virtual ~GLApplication();

	virtual void initialize();
	// duration - last frame time
	virtual void update(float duration);
	virtual void render();
	virtual void shutdown();
	virtual bool shouldCLose() const;
};
