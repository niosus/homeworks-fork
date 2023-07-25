#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_DRAWER_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_DRAWER_HPP

#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"
#include "tui_pixelator/pixelated_image.hpp"
#include "tui_pixelator/size.hpp"

namespace pixelator {

class Drawer {
 public:
  explicit Drawer(ftxui::Dimensions dimension)
      : screen_{ftxui::Screen::Create(std::move(dimension))},
        size_{screen_.dimy(), screen_.dimx() * 2} {}

  inline void Set(const PixelatedImage &image) {
    for (int row = 0; row < image.rows(); ++row) {
      for (int col = 0; col < image.cols(); ++col) {
        SetHalfPixelColor(2 * col, row, image.at(row, col));
        SetHalfPixelColor(2 * col + 1, row, image.at(row, col));
      }
    }
  }

  inline void Draw() { screen_.Print(); }
  inline std::string ToString() { return screen_.ToString(); }

  inline const Size &size() const noexcept { return size_; }
  inline int cols() const noexcept { return size_.cols; }
  inline int rows() const noexcept { return size_.rows; }

 private:
  void SetHalfPixelColor(int x, int y, const ftxui::Color &color);

  ftxui::Screen screen_;
  Size size_{};
};

}  // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_DRAWER_HPP */
