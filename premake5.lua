workspace "Anabatic"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Anabatic"
	location "Anabatic"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "anpch.h"
	pchsource "Anabatic/src/anpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AN_PLATFORM_WINDOWS",
			"AN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Anabatic/vendor/spdlog/include",
		"Anabatic/src"
	}

	links
	{
		"Anabatic"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AN_DIST"
		optimize "On"