add_executable(pixelate pixelate.cpp)
target_link_libraries(pixelate PRIVATE
  drawer
  stb_image
  pixelate_image)
