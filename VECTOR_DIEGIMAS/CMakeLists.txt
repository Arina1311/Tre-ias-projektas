cmake_minimum_required(VERSION 3.5.0)
project(vector)

include(FetchContent)
FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.14.0)

FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(vector ${SOURCES})

add_executable(testRunner test.cpp)
target_link_libraries (testRunner gtest_main gmock_main)
