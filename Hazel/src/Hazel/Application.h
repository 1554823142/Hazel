#pragma once
#include "Core.h"

namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();	//因为要被SandBox应用继承

		void Run();

	};
	// 被定义在client中
	Application* CreateApplication();
}

