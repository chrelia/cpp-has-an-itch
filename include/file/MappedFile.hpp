#pragma once

#import <string>

namespace CppHasAnItch {
    
    namespace File {

        class MappedFile {

            public:
                MappedFile(const std::string &source);
                // MappedFile(MappedFile&  mf) = delete;
                // MappedFile(MappedFile&& mf) = delete;


                ~MappedFile();
                
                const char* operator*() const;

            private: 
                std::string source;
                int fd;
                size_t size;
                char* buffer;
        };
        
    }
};