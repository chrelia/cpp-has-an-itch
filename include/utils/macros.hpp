#pragma once
#include <iostream>

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

#define ASSERT(cond, msg) \
    if (UNLIKELY(!cond)) { \
        std::cerr << "ASSERT failed : " << msg << std::endl; \
        exit(EXIT_FAILURE); \
    } \

#define ERRF(msg) \
    std::cerr << "FATAL : " << msg << std::endl; \

