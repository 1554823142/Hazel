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

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) {if(!(x)) {HZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define HZ_CORE_ASSERTION(x, ...) {if(!(x)) {HZ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)			// 1 << 0: 1; 1 << 1: 2;  1 << 3 : 8