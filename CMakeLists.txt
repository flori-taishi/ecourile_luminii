cmake_minimum_required(VERSION 3.10)
project(ecourile_luminii)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
add_executable(ecourile_luminii
    main.cpp
    Player.cpp
    Map.cpp
    Supravietuitor.cpp
    Monstru.cpp
    Abilitate.cpp
)

# Include directories
target_include_directories(ecourile_luminii PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
