#pragma once

#ifdef FI_PLATFORM_WINDOWS
	#ifdef FI_BUILD_DLL
		#define FAIRY_API __declspec(dllexport)	
	#else
		#define FAIRY_API __declspec(dllimport)
	#endif
#else
	#error FairyIsland Only Support Windows!
#endif

#ifdef FI_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { FI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { FI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif // FI_ENABLE_ASSERTS


#define BIT(x) (1 << x)