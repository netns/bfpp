cmake_minimum_required(VERSION 3.16)

project(bfpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bfpp main.cpp
    brainfuck.hpp
    brainfuck.cpp)

include(GNUInstallDirs)
install(TARGETS bfpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
