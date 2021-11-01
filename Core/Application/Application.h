#pragma once

#include "Exports.h"
#include "Events/Event.h"
#include "Events/ApplicationEvents.h"
#include "Window.h"

namespace Iridescent {

	class IRID_EXPORT Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}