#pragma once

#include <bit>
#include <cstdint>
#include <cstring>

namespace CppHasAnItch {

    namespace Utils {

        template<std::integral T>
        inline constexpr size_t BigToNative(T &val, const char* buffer) {
            std::memcpy(&val, buffer, sizeof(val));

            if (std::endian::native == std::endian::little)
                val = std::byteswap(val);

            return sizeof(val);
        }

        


    }
}