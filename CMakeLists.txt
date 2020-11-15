CMAKE_MINIMUM_REQUIRED(VERSION 3.9.0) 
PROJECT(rpg_adventure)                      

# Declare the executable target built from your sources
add_executable(Game src/v0/RPGv0.cpp)
add_executable(MakeEmptySavings src/CreateEmptySavings.cpp)

add_executable(GameV1 src/v1/main.cpp)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
