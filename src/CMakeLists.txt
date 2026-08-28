file(GLOB_RECURSE APP_LIBS "*.cpp" "*.hpp")

add_library(LIBS "${APP_LIBS}")

# PUBLIC includes the include directory with the target, does not need to be reincluded when linking ReplayEngine
target_include_directories(LIBS PUBLIC "${PROJECT_SOURCE_DIR}/include")