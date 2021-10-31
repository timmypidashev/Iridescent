#pragma once

#include "Exports.h"
#include "Events/Event.h"
#include "Window.h"

namespace Iridescent {

	class IRID_EXPORT Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}