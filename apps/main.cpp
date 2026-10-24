#include <sstream>
#include <iostream>
#include "nasdaq/ItchHandler.hpp"
#include "nasdaq/ItchParser.hpp"
#include "file/MappedFile.hpp"


using namespace CppHasAnItch;

int main() {
    
    std::stringstream path;
    path << RESOURCES_PATH << "/itch-psx/20200130.PSX_ITCH_50";

    std::cout << "Openning file" << std::endl;
    File::MappedFile file(path.str());
    
    std::cout << "Building Parser" << std::endl;

    ITCH::ItchHandler handler;
    ITCH::ItchParser parser(handler);

    std::cout << "Starting parse" << std::endl;
    parser.parse(*file, file.size());

    
    std::cout << "Parsing complete" << std::endl;
    
    return 0;
}