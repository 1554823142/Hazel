#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();	//��ΪҪ��SandBoxӦ�ü̳�

		void Run();

	};
	// ��������client��
	Application* CreateApplication();
}

