add_subdirectory(${PROJECT_SOURCE_DIR}/src/external/googletest external/googletest)
include(GoogleTest)

set(STRING_SPLIT_TEST test_string_split)
add_executable(${STRING_SPLIT_TEST} test_string_split.cpp)
target_link_libraries(${STRING_SPLIT_TEST} gtest gtest_main string_manipulation)
gtest_discover_tests(${STRING_SPLIT_TEST}
  WORKING_DIRECTORY ${PROJECT_DIR}
  PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)
