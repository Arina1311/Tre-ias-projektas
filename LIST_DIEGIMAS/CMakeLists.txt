cmake_minimum_required(VERSION 3.0.0)
project(list)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(list ${SOURCES})