cmake_minimum_required(VERSION 3.14)

project(a1)

Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.9)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/_deps/catch2-src/contrib")

include(CTest)
include(Catch)

add_subdirectory(src)
add_subdirectory(tests)

