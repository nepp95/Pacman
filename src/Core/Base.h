#pragma once

#include "Core/PlatformDetection.h"

// Platform dependent debugbreak
#ifdef DEBUG
    #if defined(PLATFORM_WINDOWS)
        #define DEBUGBREAK() __debugbreak()
    #elif defined(PLATFORM_MACOS)
        #define DEBUGBREAK() __builtin_debugtrap()
    #elif defined(PLATFORM_LINUX)
        #define DEBUGBREAK() asm("int $3")
    #endif
#else
    #define EP_DEBUGBREAK()
#endif

// Assertion macros
#include "Core/Assert.h"