#pragma once

#include <cstddef>
#include <cstring>
#include <string>

namespace CppHasAnItch {

    namespace Utils {

        static inline size_t ParseToString(char* val, const char* buffer, size_t size) {
            std::memcpy(val, buffer, size);
            return size;
        }
        
    }
}