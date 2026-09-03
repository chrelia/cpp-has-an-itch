#pragma once

#import <string>

namespace replay {

    class ReplayEngine {

        public:
            ReplayEngine(const std::string &source);

        private: 
            std::string source;
            int fildesc;
            char* buffer;
    };
};