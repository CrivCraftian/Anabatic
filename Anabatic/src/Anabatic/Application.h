#pragma once

#include "Core.h"

namespace Anabatic
{
	class AN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}