#pragma once

#include "Hunchback\Core.h"

namespace Hunchback {

	class HUNCHBACK_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();

}