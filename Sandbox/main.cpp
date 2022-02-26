#include <Iridescent.h>
#include "imgui.h"

class IridLayer : public Iridescent::Layer
{
public:
    IridLayer()
        : Layer("Irid")
    {
    }

    void OnUpdate() override
    {
        if (Iridescent::Input::IsKeyPressed(IRID_KEY_TAB))
			IRID_TRACE("Tab key is pressed (poll)!");
    }

    virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

    void OnEvent(Iridescent::Event& event) override
    {
        if (event.GetEventType() == Iridescent::EventType::KeyPressed)
		{
			Iridescent::KeyPressedEvent& e = (Iridescent::KeyPressedEvent&)event;
			if (e.GetKeyCode() == IRID_KEY_TAB)
				IRID_TRACE("Tab key is pressed (event)!");
			IRID_TRACE("{0}", (char)e.GetKeyCode());
		}
    }

};

class Sandbox : public Iridescent::Application
{
public:
	Sandbox()
	{
        PushLayer(new IridLayer());
	}

	~Sandbox()
	{

	}

};

Iridescent::Application* Iridescent::CreateApplication()
{
	return new Sandbox();
}
