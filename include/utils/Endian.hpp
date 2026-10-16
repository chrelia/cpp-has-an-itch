#pragma once

#include <bit>
#include <cstdint>
#include <cstring>

namespace CppHasAnItch {

    namespace Utils {
        
        template<std::integral T>
        inline constexpr void BigToNative(T &val) {
            if (std::endian::native == std::endian::big)
                return;
            val = std::byteswap(val);
        }

        inline constexpr void BigToNative(uint8_t *val) {
            if (std::endian::native == std::endian::big)
                return;
            
            uint64_t tmp;
            
            std::memcpy(&tmp, val, 6);
            BigToNative(tmp);
            std::memcpy(val, &tmp, 6);
            
        }


    }
}