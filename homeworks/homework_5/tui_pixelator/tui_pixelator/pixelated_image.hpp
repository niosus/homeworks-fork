#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATED_IMAGE_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATED_IMAGE_HPP

#include "ftxui/screen/color.hpp"
#include "tui_pixelator/size.hpp"

namespace pixelator {

class PixelatedImage {
 public:
  PixelatedImage() = default;

  explicit PixelatedImage(const Size& size)
      : size_{size}, pixels_(size_.rows * size_.cols, ftxui::Color{}) {}

  PixelatedImage(int rows, int cols) : PixelatedImage{Size{rows, cols}} {}

  ftxui::Color& at(int row, int col) { return pixels_[Index(row, col)]; }
  const ftxui::Color& at(int row, int col) const {
    return pixels_[Index(row, col)];
  }

  const Size& size() const noexcept { return size_; }
  int cols() const noexcept { return size_.cols; }
  int rows() const noexcept { return size_.rows; }

 private:
  std::size_t Index(int row, int col) const { return row * size_.cols + col; }

  Size size_{};
  std::vector<ftxui::Color> pixels_{};
};

}  // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATED_IMAGE_HPP \
        */
