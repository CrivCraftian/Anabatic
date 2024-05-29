#include <Anabatic.h>

class Sandbox : public Anabatic::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Anabatic::Application* Anabatic::CreateApplication()
{
	return new Sandbox();
}
