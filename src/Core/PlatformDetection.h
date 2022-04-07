#pragma once

// Platform detection
#if defined(_WIN64) || defined(WIN64)
    // Win64
#elif defined(_WIN32) || defined(WIN32)
    // Win32
#elif defined(__APPLE__) && defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        // iOS in XCode simulator
    #elif TARGET_OS_IPHONE == 1
        // iOS on iPhone, iPad, etc.
    #elif TARGET_OS_MAC == 1
        // MacOS
    #endif
#elif defined(__linux__)
    #error "Linux is not supported!"
#endif

// Supported platforms
#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_MACOS)
    #define SUPPORTED_PLATFORM
#endif

#ifndef SUPPORTED_PLATFORM
    #error "Not a supported platform!"
#endif