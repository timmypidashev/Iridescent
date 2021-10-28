#pragma once

#ifdef IRID_EXPORT

extern Iridescent::Application* Iridescent::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Iridescent::CreateApplication();
	app->Run();
	delete app;
}

#endif