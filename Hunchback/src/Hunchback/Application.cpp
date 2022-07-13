#include "Application.h"

#include "Hunchback\Events\ApplicationEvent.h"
#include "Hunchback\Events\KeyEvent.h"
#include "Hunchback\Log.h"

namespace Hunchback {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e1(1280, 720);
		if (e1.IsInCategory(EventCategoryApplication))
		{
			HNBK_TRACE(e1);
		}
		if (e1.IsInCategory(EventCategoryInput))
		{
			HNBK_TRACE(e1);
		}

		KeyPressedEvent e2(23, 5);
		if (e2.IsInCategory(EventCategoryKeyboard) && e2.IsInCategory(EventCategoryInput))
		{
			HNBK_TRACE(e2);
			e2 = KeyPressedEvent(42, 8);
			HNBK_TRACE(e2);
		}

		HNBK_CORE_TRACE("This is a core trace!");
		HNBK_CORE_INFO("This is a core info log!");
		HNBK_CORE_WARN("This is a core warning!");
		HNBK_CORE_ERROR("This is a core error!");
		HNBK_CORE_FATAL("This is a fatal core error!\n");

		HNBK_TRACE("This is a client trace!");
		HNBK_INFO("This is a client info log!");
		HNBK_WARN("This is a client warning!");
		HNBK_ERROR("This is a client error!");
		HNBK_FATAL("This is a fatal client error!");

		while (true);
	}

}