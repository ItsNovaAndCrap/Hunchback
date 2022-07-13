#pragma once

#ifdef HNBK_PLATFORM_WINDOWS
	#ifdef HNBK_BUILD_DLL
		#define HUNCHBACK_API __declspec(dllexport) 
	#else
		#define HUNCHBACK_API __declspec(dllimport)
	#endif
#else
	#error Hunchback currently only supports Windows!
#endif

#define BIT(x) (1 << x)