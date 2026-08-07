#pragma once

#include <fstream>
#include <string>


class ReplayEngine {

public:
    ReplayEngine(std::string& src) {

        fstream.open(src, std::ios::binary);
        
    }

private:
    std::ifstream fstream;


};