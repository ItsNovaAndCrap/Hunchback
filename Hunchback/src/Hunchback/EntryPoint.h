#pragma once

#include <Hunchback\Log.h>

#ifdef HNBK_PLATFORM_WINDOWS
	
extern Hunchback::Application* Hunchback::CreateApplication();

int main(int argc, char** argv)
{
	Hunchback::Log::Init();
	auto app = Hunchback::CreateApplication();
	app->Run();
	delete app;
}

#endif