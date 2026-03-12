cmake_minimum_required(VERSION 3.16)
project(ReCubed)

set(CMAKE_CXX_STANDARD 17)

# Default to Debug if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(SFML 2.6 COMPONENTS graphics window audio system REQUIRED)

add_executable(ReCubed src/main.cpp)
target_link_libraries(ReCubed sfml-graphics sfml-window sfml-audio sfml-system)
target_compile_options(ReCubed PRIVATE -Wall -Wextra -Wpedantic)
