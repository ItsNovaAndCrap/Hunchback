#pragma once

#include <Hunchback\Log.h>

#ifdef HNBK_PLATFORM_WINDOWS
	
extern Hunchback::Application* Hunchback::CreateApplication();

int main(int argc, char** argv)
{
	Hunchback::Log::Init();
	HNBK_CORE_WARN("Initialized Log!");
	int a = 5;
	HNBK_INFO("Hello World! Var={0}", a);

	auto app = Hunchback::CreateApplication();
	app->Run();
	delete app;
}

#endif