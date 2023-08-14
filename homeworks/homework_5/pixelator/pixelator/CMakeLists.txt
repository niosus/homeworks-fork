add_library(stb_image_data_view stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup ftxui::screen stb::stb)

add_library(image INTERFACE)
target_link_libraries(image INTERFACE cxx_setup ftxui::screen stb::stb)

add_library(drawer drawer.cpp)
target_link_libraries(drawer PUBLIC cxx_setup ftxui::screen stb::stb)

add_library(pixelate_image pixelate_image.cpp)
target_link_libraries(pixelate_image PUBLIC cxx_setup stb_image_data_view image)

if(BUILD_TESTING)
  include(GoogleTest)
  add_executable(tui_pixelator_tests
    drawer_test.cpp
    pixelate_image_test.cpp
    image_test.cpp
    stb_image_data_view_test.cpp)
  target_link_libraries(tui_pixelator_tests PRIVATE
    cxx_setup drawer stb_image_data_view image pixelate_image GTest::gtest_main)
  gtest_discover_tests(tui_pixelator_tests)
endif()
