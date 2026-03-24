cmake_minimum_required(VERSION 3.16)
project(ReCubed)

set(CMAKE_CXX_STANDARD 17)

# Default to Debug if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(SFML 2.6 COMPONENTS graphics window audio system REQUIRED)

add_executable(ReCubed
    src/main.cpp
    src/Globals.cpp

    src/entities/Player.cpp

    src/game/Game.cpp

    src/grid/Grid.cpp

    src/input/InputHandler.cpp

    src/levels/LevelBuilder.cpp
    src/levels/LevelParser.cpp

    # src/states/LevelCompleteState.cpp
    # src/states/LevelSelectState.cpp
    # src/states/MainMenuState.cpp
    # src/states/PauseState.cpp
    src/states/PlayingState.cpp

    src/ui/components/Button.cpp
)
target_link_libraries(ReCubed sfml-graphics sfml-window sfml-audio sfml-system)
target_compile_options(ReCubed PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(ReCubed PRIVATE src/)
