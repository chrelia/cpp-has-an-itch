#include <sstream>
#include "itch/ItchParser.hpp"
#include "replay/ReplayEngine.hpp"

int main() {
    
    std::stringstream path;
    path << RESOURCES_PATH << "/itch-psx/20200130.PSX_ITCH_50";

    replay::ReplayEngine replay(path.str());
    
    
    
    return 0;
}