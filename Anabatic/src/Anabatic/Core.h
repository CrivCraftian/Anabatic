#pragma once

#ifdef AN_PLATFORM_WINDOWS
	#ifdef AN_BUILD_DLL
		#define AN_API __declspec(dllexport)
	#else
		#define AN_API __declspec(dllimport)
	#endif // AN_BUILD_DLL

#else
	#error Anabatic only supports windows
#endif // AN_PLATFORM_WINDOWS
