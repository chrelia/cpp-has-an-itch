#pragma once

#import <string>

namespace replay {

    class ReplayEngine {

        public:
            ReplayEngine(const std::string &source);
            ~ReplayEngine();
            
            void replay();

        private: 
            std::string source;
            int fd;
            size_t size;
            char* buffer;
    };
};