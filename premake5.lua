workspace "Hunchback"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hunchback"
	location "Hunchback"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines
		{
			"HNBK_PLATFORM_WINDOWS",
			"HNBK_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HNBK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HNBK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HNBK_DIST"
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
		"Hunchback/src",
		"Hunchback/vendor/spdlog/include"
	}

	links
	{
		"Hunchback"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines
		{
			"HNBK_PLATFORM_WINDOWS",
			"_MBCS"
		}

	filter "configurations:Debug"
		defines "HNBK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HNBK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HNBK_DIST"
		optimize "On"