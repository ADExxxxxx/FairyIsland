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

namespace FI 
{

}