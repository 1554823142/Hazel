#pragma once
#include "Core.h"

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

