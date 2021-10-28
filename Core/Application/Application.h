#pragma once

#include "Exports.h"

namespace Iridescent {

	class IRID_EXPORT Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}