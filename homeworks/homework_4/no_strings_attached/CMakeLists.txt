cmake_minimum_required(VERSION 3.16..3.29)
project(no_strings_attached VERSION 0.0.1
                            DESCRIPTION "String processing library"
                            LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(no_strings_attached INTERFACE)

if(UNIX)
    target_compile_options(no_strings_attached INTERFACE -Wall -Wpedantic -Wextra)
endif()
target_compile_features(no_strings_attached INTERFACE cxx_std_17)
target_include_directories(no_strings_attached INTERFACE ${PROJECT_SOURCE_DIR})