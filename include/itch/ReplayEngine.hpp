#include <fstream>
#include <string>

namespace itch {

    class ReplayEngine {
        
        public:
            ReplayEngine(const std::string& src);


        private:
            std::fstream file;
    };

};