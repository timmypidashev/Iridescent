#include "Application.h"

#include <iostream>

namespace Iridescent {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Application Run" << std::endl;
		while (true);
	}

}