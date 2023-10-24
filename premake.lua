workspace "FairyIsland"
    architecture "x64"
    configurations { "Debug", "Release" }

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