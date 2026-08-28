#include <sstream>
#include "itch/ReplayEngine.hpp"

int main() {
    
    std::stringstream file;
    file << RESOURCES_PATH << "/itch-psx/20200130.PSX_ITCH_50";

    auto replay = itch::ReplayEngine(file.str());
    
    return 0;
}