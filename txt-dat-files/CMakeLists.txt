cmake_minimum_required(VERSION 3.31)
project(Project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project2 main.cpp FileReader.cpp FileReader.h Inventory.cpp Inventory.h Menu.cpp Menu.h)
