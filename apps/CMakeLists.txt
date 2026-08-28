add_executable(main main.cpp)

target_link_libraries(main PRIVATE LIBS)
target_compile_definitions(main PRIVATE RESOURCES_PATH="${PROJECT_SOURCE_DIR}/resources")