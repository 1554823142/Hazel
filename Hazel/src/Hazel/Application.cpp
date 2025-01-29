#include "hzpch.h"

#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/log.h"

namespace Hazel {
	Application::Application()
	{
		
	}
	Application::~Application() 
	{

	}
	void Application::Run()
	{
		WindowResizeEvent e(1260, 720);
		// HZ_TRACE(e);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE("{}", e.ToString());
		}
		while (1);
	}
}