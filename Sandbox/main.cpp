#include <Iridescent.h>

class Sandbox : public Iridescent::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Iridescent::Application* Iridescent::CreateApplication()
{
	return new Sandbox();
}