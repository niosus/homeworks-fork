cmake_minimum_required(VERSION 3.16..3.24)
project(no_strings_attached
    VERSION 0.0.1
    DESCRIPTION "Our first project"
    LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

include(cmake/UpdateSubmodules.cmake)

add_library(cxx_defaults INTERFACE)
target_compile_options(cxx_defaults
  INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_defaults INTERFACE cxx_std_17)
target_include_directories(cxx_defaults
  INTERFACE ${PROJECT_SOURCE_DIR}/src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

add_subdirectory(no_strings_attached)
add_subdirectory(validation_tests)
