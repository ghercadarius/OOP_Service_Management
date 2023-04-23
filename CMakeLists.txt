cmake_minimum_required(VERSION 3.24)
project(pr2_clion)

set(CMAKE_CXX_STANDARD 17)

add_executable(pr2_clion main.cpp masini.h meniu.h meniu.cpp stocare.h masini.cpp stocare.cpp exceptions.h)
