#pragma once	

#include "config.h"

#ifdef IRID_EXPORT

extern Iridescent::Application* Iridescent::CreateApplication();

int main(int argc, char** argv)
{	
	Iridescent::Log::Init();
	IRID_CORE_INFO("Initialized Core Logger!");
	IRID_INFO("Initialized Client Logger!");

	auto app = Iridescent::CreateApplication();
	app->Run();
	delete app;
}

#endif