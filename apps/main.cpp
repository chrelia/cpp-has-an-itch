#include <sstream>
#include <iostream>
#include "nasdaq/ItchParser.hpp"
#include "file/MappedFile.hpp"


using namespace CppHasAnItch;

int main() {
    
    std::stringstream path;
    path << RESOURCES_PATH << "/itch-psx/20200130.PSX_ITCH_50";

    File::MappedFile file(path.str());
    

    
    
    
    return 0;
}