#include <iostream>
#include <fstream>

int main() {
    std::cout << "Opening file..." << std::endl;

    std::ifstream fstream("../data/itch-psx/20200130.PSX_ITCH_50", std::ios::binary);

    if (!fstream.is_open()) {
        std::cout << "Failed to open" << std::endl;
        return -1;
    }

    std::cout << "File opened" << std::endl;

    fstream.close();

    std::cout << "File closed" << std::endl;
    return 0;
}