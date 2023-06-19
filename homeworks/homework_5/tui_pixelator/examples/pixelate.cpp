#include "tui_pixelator/pixelate.hpp"
#include "tui_pixelator/drawer.hpp"
#include "tui_pixelator/stb_image.hpp"

#include <cstddef>
#include <filesystem>
#include <iostream>
#include <utility>

namespace {
using pixelator::Drawer;
using pixelator::StbImage;
using pixelator::Pixelate;
}  // namespace

int main(int argc, char** argv) {
  if (argc < 2) { std::cerr << "No image provided." << std::endl; }

  const StbImage image{argv[1]};
  if (image.empty()) {
    std::cerr << "Image could not be loaded" << std::endl;
    exit(1);
  }
  Drawer drawer{ftxui::Dimension::Full()};

  const auto pixelated_image = Pixelate(image, drawer.size());

  for (int col = 0; col < pixelated_image.cols(); ++col) {
    for (int row = 0; row < pixelated_image.rows(); ++row) {
      drawer.SetPixelColor(row, col, pixelated_image.at(row, col));
    }
  }

  drawer.Draw();
  return 0;
}
