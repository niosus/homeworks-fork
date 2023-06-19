#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_DRAWER_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_DRAWER_HPP

#include "tui_pixelator/size.hpp"

#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"

namespace pixelator {

class Drawer {
public:
  Drawer(ftxui::Dimensions dimension)
      : screen_{ftxui::Screen::Create(std::move(dimension))},
        size_{screen_.dimy(), screen_.dimx() / 2} {}

  void SetPixelColor(int row, int col, const ftxui::Color &color);

  ftxui::Color &ColorAt(int row, int col);

  void Draw() { screen_.Print(); }

  const Size &size() const noexcept { return size_; }
  int cols() const noexcept { return size_.cols; }
  int rows() const noexcept { return size_.rows; }

private:
  void SetHalfPixelColor(int x, int y, const ftxui::Color &color);

  ftxui::Screen screen_;
  Size size_{};
};

} // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_DRAWER_HPP */
