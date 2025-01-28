#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only support Window!
#endif // HZ_BUILD_DLL

#define BIT(x) (1 << x)			// 1 << 0: 1; 1 << 1: 2;  1 << 3 : 8