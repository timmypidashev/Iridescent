#include <Iridpch.h>

#include "Application.h"
#include "Events/ApplicationEvents.h"
#include "Logger/Log.h"

namespace Iridescent {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			IRID_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			IRID_TRACE(e);
		}

		while (true);
	}

}