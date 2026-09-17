#include "nasdaq/ItchParser.hpp"
#include "nasdaq/ItchTypes.hpp"

namespace Scratch {


    namespace ITCH {

        void parse(const char* buffer, size_t size) {

            size_t index = 0;

            while (index < size) {

                size_t offset = 0;

                auto type = buffer[offset];

                switch (type) {

                    case static_cast<char>(MessageType::SystemEventMessage): {

                    }
                }





            }
        }

        SystemEventMessage parseSystenEventMessage(char* buffer, size_t size) {

        }

        
    }

    
   
};