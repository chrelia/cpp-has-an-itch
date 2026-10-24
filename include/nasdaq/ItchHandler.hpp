#pragma once


#include <iostream>
#include "nasdaq/ItchFormat.hpp"

namespace CppHasAnItch {

    namespace ITCH {

        class ItchHandler {

            public:
                
                template<class Message>
                void handleMessage(Message &m) {
                    // std::cout << "Message Handling" << std::endl;
                    std::cout << m << std::endl;
                    if (count++ == 10) 
                        exit(0);

                }
            
            private:
                
                size_t count = 0;
        };

    }

}