#include <string>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file/MappedFile.hpp"
#include "utils/macros.hpp"



namespace Scratch {

    namespace File {

        MappedFile::MappedFile(const std::string &source)
        : source(source)
        { 
            ASSERT(!source.empty(), "source is empty");

            fd = open(source.c_str(), O_RDONLY);    
            ASSERT((fd != -1), "failed to open file");

            struct stat st;
            fstat(fd, &st);

            // get whole file size to map in memory
            size = st.st_size;
            ASSERT((size > 0), "size of file <= 0")


            buffer = static_cast<char*>(mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0));

            if (buffer == MAP_FAILED) {
                close(fd);
                ERRF("failed to create mapping");
            }
        }

        MappedFile::~MappedFile() {
            if (fd != -1) {
                close(fd);
            }

            if (buffer != MAP_FAILED) {
                munmap(buffer, size);
            }
        }


        const char* MappedFile::operator*() const {
            return buffer;
        }
    }


    
};