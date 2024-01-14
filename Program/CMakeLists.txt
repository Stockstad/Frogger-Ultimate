cmake_minimum_required(VERSION 3.16)
project(Frogger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Add your source files
add_executable(Frogger main.cpp
        GameManager.h
        Truck.h
        Player.cpp
        GameObject.h
        Sprite.h
        Sprite.cpp
        Truck.cpp
        GameObject.cpp
        GameManager.cpp
        Turtle.cpp
        Turtle.h
        Home.h
        Home.cpp
        main.cpp
        State.h
        GameState.h
        MenuState.h
        ExitState.h
        GameState.cpp
        State.cpp
        MenuState.cpp
        Text.cpp
        Text.h
        ExitState.cpp
        SoundManager.cpp
        SoundManager.h)

# Include SFML headers
target_include_directories(Frogger PRIVATE ${SFML_INCLUDE_DIRS})

# Link SFML
target_link_libraries(Frogger PRIVATE sfml-graphics sfml-audio)