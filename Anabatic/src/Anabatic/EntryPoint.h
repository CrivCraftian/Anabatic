#pragma once

#ifdef AN_PLATFORM_WINDOWS

extern Anabatic::Application* Anabatic::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Anabatic::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Anabatic does not support your operating system
#endif // AN_PLATFORM_WINDOWS
