workspace "FairyIsland"
    architecture "x64"
    configurations 
    { 
        "Debug", 
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FairyIsland"
    location "FairyIsland"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir ("bin-int/" .. outputdir .."/%{prj.name}")


    files { "**.h", "**.cpp" }

    filter { "configurations:Debug" }
        defines { "DEBUG" }
        symbols "On"

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"


project "FairyIsland"
        kind "ConsoleApp"
        language "C++"
        files { "**.h", "**.cpp" }
    
        filter { "configurations:Debug" }
            defines { "DEBUG" }
            symbols "On"
    
        filter { "configurations:Release" }
            defines { "NDEBUG" }
            optimize "On"