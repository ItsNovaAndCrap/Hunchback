#include <Hunchback.h>

class Sandbox : public Hunchback::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
	
};

Hunchback::Application* Hunchback::CreateApplication()
{
	return new Sandbox();
}