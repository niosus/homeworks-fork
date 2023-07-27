#include "tui_pixelator/drawer.hpp"

#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"

namespace pixelator {

void Drawer::SetHalfPixelColor(int x, int y, const ftxui::Color &color) {
  auto &pixel = screen_.PixelAt(x, y);
  pixel.background_color = color;
  pixel.character = ' ';
}

}  // namespace pixelator
