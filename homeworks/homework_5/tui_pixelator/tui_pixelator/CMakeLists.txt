add_library(stb_image stb_image.cpp)
target_link_libraries(stb_image PUBLIC cxx_setup ftxui::screen stb::stb)

add_library(pixelated_image INTERFACE)
target_link_libraries(pixelated_image INTERFACE cxx_setup ftxui::screen stb::stb)

add_library(drawer drawer.cpp)
target_link_libraries(drawer PUBLIC cxx_setup ftxui::screen stb::stb)

add_library(pixelate_image pixelate.cpp)
target_link_libraries(pixelate_image PUBLIC cxx_setup stb_image pixelated_image)

if (BUILD_TESTING)
    include(GoogleTest)
    add_executable(drawer_test drawer_test.cpp)
    target_link_libraries(drawer_test PRIVATE drawer GTest::gtest_main)

    gtest_discover_tests(drawer_test)
endif()
