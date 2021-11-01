#define GLFW_INCLUDE_NONE

#include <Iridpch.h>

#include "Application.h"

#include <glad/glad.h>

#include "GLFW/glfw3.h"

namespace Iridescent {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

}