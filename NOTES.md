## Build System Notes (cmake)

### For the main executable
- cmake_minimum_required sets the minmum required version for cmake, can also have a range 
- set(CMAKE_CXX_STANDARD 23) sets the C++ standard using the CMAKE_CXX_STANDARD cmake variable
- add_executable(main main.cpp) adds an executable with target name main
- target_include_directories(main1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/") all the header files inside the /include directory will be included 
- add_subdirectory and target_link_libraries has to do with linking libraries. add_subdiretory  tells cmake where to find the library (other CMakeList.txt files) and target_link_libraries tells it which library should be linked to which target.

### For definining libraries
- add_library(target TYPE) tells cmake that the specific target is a library, and can find and link it when using target_link_libraries
