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
	#define FI_ASSERT(x, ...) { if(!(x)) { FI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FI_CORE_ASSERT(x, ...) { if(!(x)) { FI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FI_ASSERT(x, ...)
	#define FI_CORE_ASSERT(x, ...)
#endif // FI_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define FI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)