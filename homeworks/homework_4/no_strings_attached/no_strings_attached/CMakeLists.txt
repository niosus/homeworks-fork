add_library(string_split INTERFACE)
target_link_libraries(string_split INTERFACE cxx_defaults)

add_library(string_trim INTERFACE)
target_link_libraries(string_trim INTERFACE cxx_defaults)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(${PROJECT_SOURCE_DIR}/external/googletest external/googletest)
    include(GoogleTest)

    set(TESTS test_string_lib)
    add_executable(${TESTS}
        string_split_test.cpp
        string_trim_test.cpp)
    target_link_libraries(${TESTS} PRIVATE GTest::gtest_main string_split string_trim)
    gtest_discover_tests(${TESTS} WORKING_DIRECTORY ${PROJECT_DIR})
endif()
