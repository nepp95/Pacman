#pragma once

#ifdef DEBUG
#include <iostream>

// Assert
#define CORE_ASSERT(condition, msg) if(!(condition)) { std::cout << "Assertion failed!\nMessage: " << msg << std::endl; DEBUGBREAK(); }
#define ASSERT(condition, msg) if(!(condition)) { std::cout << "Assertion failed!\nMessage: " << msg << std::endl; }

// Logging
#define CORE_LOG(msg) std::cout << __FILE__ << "(" << __LINE__ << "): " << msg << std::endl; 

#else
// Assert
#define CORE_ASSERT(condition, msg)
#define ASSERT(condition, msg)

// Logging
#define CORE_LOG(msg)

#endif