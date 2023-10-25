workspace "FairyIsland"
    architecture "x64"
    configurations 
    { 
        "Debug", 
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
--- Include SubModule
IncludeDir = {}
IncludeDir["GLFW"] = "FairyIsland/vendor/GLFW/include"

include "FairyIsland/vendor/GLFW"

project "FairyIsland"
    location "FairyIsland"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir ("bin-int/" .. outputdir .."/%{prj.name}")
    pchheader "pch.h"
    pchsource "FairyIsland/src/pch.cpp"

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FI_PLATFORM_WINDOWS",
            "FI_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "FI_DEBUG"
        symbols "on"
    
    filter "configurations:Release"
        defines "FI_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "FI_DIST"
        optimize "on"


project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir ("bin-int/" .. outputdir .."/%{prj.name}")


    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "FairyIsland/vendor/spdlog/include",
        "FairyIsland/src"
    }

    links
    {
        "FairyIsland"
    }

    filter "system:windows"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "FI_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FI_DEBUG"
        symbols "on"
    
    filter "configurations:Release"
        defines "FI_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "FI_DIST"
        optimize "on"