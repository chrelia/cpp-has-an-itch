#include <iostream>
#include <fstream>
#include <string>
#include "itch/ReplayEngine.hpp"
#include "utils/macros.hpp"


namespace itch {

    ReplayEngine::ReplayEngine(const std::string& src) {
        
        ASSERT(!src.empty(), "src is empty");

        std::cout << "src : " << src << std::endl;

        std::cout << "Opening file..." << std::endl;

        std::ifstream fstream(src, std::ios::binary);
        

        ASSERT(fstream.is_open(), "fstream failed to open");

        std::cout << "File opened" << std::endl;

        fstream.close();

        std::cout << "File closed" << std::endl;
        
    }

   
};