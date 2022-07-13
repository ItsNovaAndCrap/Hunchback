#pragma once

#include "Hunchback\Core.h"
#include "Hunchback\Events\Event.h"

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