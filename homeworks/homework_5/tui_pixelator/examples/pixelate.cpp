#include "tui_pixelator/pixelate.hpp"

#include <cstddef>
#include <filesystem>
#include <iostream>
#include <utility>

#include "tui_pixelator/drawer.hpp"
#include "tui_pixelator/stb_image.hpp"

namespace {
using pixelator::Drawer;
using pixelator::Pixelate;
using pixelator::StbImage;
}  // namespace

int main(int argc, char **argv) {
  if (argc < 2) { std::cerr << "No image provided." << std::endl; }

  const StbImage image{argv[1]};
  if (image.empty()) {
    std::cerr << "Image could not be loaded" << std::endl;
    exit(1);
  }
  Drawer drawer{ftxui::Dimension::Full()};

  drawer.Set(Pixelate(image, drawer.size()));
  drawer.Draw();
  return 0;
}
