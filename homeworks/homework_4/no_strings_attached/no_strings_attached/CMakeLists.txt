add_library(string_split INTERFACE)
target_link_libraries(string_split INTERFACE cxx_defaults)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    # add_subdirectory(tests)
endif()
