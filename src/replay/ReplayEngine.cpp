#include <string>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "replay/ReplayEngine.hpp"
#include "utils/macros.hpp"



namespace replay {

    
    ReplayEngine::ReplayEngine(const std::string &source)
    : source(source)
    { 
        ASSERT(!source.empty(), "source is empty");

        fildesc = open(source.c_str(), O_RDONLY);    
        ASSERT((fildesc != -1), "failed to open file");

        struct stat st;
        fstat(fildesc, &st);

        // get whole file size to map in memory
        size_t size = st.st_size;
        ASSERT((size > 0), "size of file < 0")


        buffer = static_cast<char*>(mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fildesc, 0));

        if (buffer == MAP_FAILED) {
            close(fildesc);
            ERRF("failed to create mapping");
        }

    }



    
};