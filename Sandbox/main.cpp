#include <Iridescent.h>

class IridLayer : public Iridescent::Layer
{
public:
    IridLayer()
        : Layer("Irid")
    {
    }

    void OnUpdate() override
    {
        IRID_INFO("IridLayer::Update");
    }

    void OnEvent(Iridescent::Event& event) override
    {
        IRID_TRACE("{0}", event);
    }

};

class Sandbox : public Iridescent::Application
{
public:
	Sandbox()
	{
        PushLayer(new IridLayer());
        PushOverlay(new Iridescent::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Iridescent::Application* Iridescent::CreateApplication()
{
	return new Sandbox();
}
