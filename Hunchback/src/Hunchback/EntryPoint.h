#pragma once

#ifdef HNBK_PLATFORM_WINDOWS
	
extern Hunchback::Application* Hunchback::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hunchback::CreateApplication();
	app->Run();
	delete app;
}

#endif