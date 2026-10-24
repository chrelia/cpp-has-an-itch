#pragma once

#import <string>

namespace CppHasAnItch {
    
    namespace File {

        class MappedFile {

            public:
                MappedFile(const std::string &source);
                MappedFile(MappedFile&  mf) = delete;
                MappedFile(MappedFile&& mf) = delete;

                ~MappedFile();

                size_t size() const;
                
                const char* operator*() const;

            private: 
                std::string source;
                int fd;
                size_t sz;
                char* buffer;
        };
        
    }
};