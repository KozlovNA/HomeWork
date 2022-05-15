cmake_minimum_required(VERSION 3.21)
project(DynamicProg)

set(CMAKE_CXX_STANDARD 23)

add_executable(DynamicProg main.cpp)

add_executable(main main.cpp)
add_executable(WhitePawn WhitePawn.cpp)
add_executable(LIS LIS.cpp)
add_executable(NailsNRopes NailsNRopes.cpp)
add_executable(poligon cmake-build-debug/poligon.cpp)
add_executable(VideoGame VideoGame.cpp)