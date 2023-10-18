#include "app/GLApplication.h"

#include <stdexcept>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <fmtlog/fmtlog.h>

static void glfwErrorCallback(int error, const char* description)
{
	loge("GLFW Error Code {}: {}", error, description);
	throw std::runtime_error(description);
}

GLApplication::~GLApplication()
{
	shutdown();
}

void GLApplication::initialize()
{
	glfwSetErrorCallback(glfwErrorCallback);
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	m_window = glfwCreateWindow(800, 600, "Game Animation", nullptr, nullptr);
	logi("Window created");

	glfwMakeContextCurrent(m_window);
	gladLoadGL();
	logi("GL loaded");

	// Enable vsync
	glfwSwapInterval(1);
}

void GLApplication::update(float)
{
	glfwPollEvents();
}

void GLApplication::render()
{
	glfwSwapBuffers(m_window);
}

void GLApplication::shutdown()
{
	if (m_window != nullptr)
	{
		glfwDestroyWindow(m_window);
		m_window = nullptr;
	}
	glfwTerminate();
}

bool GLApplication::shouldCLose() const
{
	return glfwWindowShouldClose(m_window) != 0;
}