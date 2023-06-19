#include "tui_pixelator/drawer.hpp"

#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"

namespace pixelator {

void Drawer::SetPixelColor(int row, int col, const ftxui::Color &color) {
  SetHalfPixelColor(2 * col, row, color);
  SetHalfPixelColor(2 * col + 1, row, color);
}
ftxui::Color &Drawer::ColorAt(int row, int col) {
  return screen_.PixelAt(2 * col, row).background_color;
}

void Drawer::SetHalfPixelColor(int x, int y, const ftxui::Color &color) {
  auto &pixel = screen_.PixelAt(x, y);
  pixel.background_color = color;
  pixel.character = ' ';
}

} // namespace pixelator
