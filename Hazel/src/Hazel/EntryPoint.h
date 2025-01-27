#pragma once

#ifdef HZ_PLATFORM_WINDOWS

/// Entry Point
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc, int** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initailized Log!");
	int a = 5;
	HZ_INFO("Hello Guy, and a is {0}", a);
	printf("Start Hazel Engine!\n");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS

