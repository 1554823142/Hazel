#pragma once

#ifdef HZ_PLATFORM_WINDOWS

/// Entry Point
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc, int** argv)
{
	printf("Start Hazel Engine!\n");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS

