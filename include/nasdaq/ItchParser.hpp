#pragma once

#include "nasdaq/ItchTypes.hpp"
#include "utils/Macros.hpp"
#include <cstddef>
#include <cstring>

namespace CppHasAnItch {

    namespace ITCH {
        
        template <class Handler>
        class ItchParser {
            
            public:
                ItchParser() = delete;
                ItchParser(const ItchParser &parser) = delete;
                ItchParser(ItchParser &&parser) = delete;

                explicit ItchParser(Handler& handler): _handler(handler) {}

                inline void parse(const char* buffer, size_t size);

                template <class Message>
                inline void parseMessage(Message &m, const char* buffer, size_t size, size_t offset = 0);
           
            private:
                Handler _handler;

        };

        template<class Handler>
        void ItchParser<Handler>::parse(const char* buffer, size_t size) {

            size_t index = 0;

            while (index < size) {

                auto type = buffer[index];

                switch (type) {

                    case SystemEventMessage::MessageType: {
                        SystemEventMessage m;
                        parseMessage(m, buffer, size);
                    }
                }





            }
        }





        
    }
}