#pragma once

#include "Exports.h"
#include "Window.h"
#include "Layer/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvents.h"
#include "ImGui/ImGuiLayer.h"

namespace Iridescent {

	class IRID_EXPORT Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
    
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
