#pragma once

#ifdef DEBUG
#include <iostream>

#define ASSERT(condition, msg) if(!(condition)) { std::cout << "Assertion failed!\nMessage:" << msg << std::endl; }
#else
#define ASSERT(condition, msg)
#endif