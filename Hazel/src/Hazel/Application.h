#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();	//因为要被SandBox应用继承

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running; 
	};
	// 被定义在client中
	Application* CreateApplication();
}

