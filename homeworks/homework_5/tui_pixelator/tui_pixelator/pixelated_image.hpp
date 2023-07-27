#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATED_IMAGE_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATED_IMAGE_HPP

#include "ftxui/screen/color.hpp"
#include "tui_pixelator/size.hpp"

namespace pixelator {

class PixelatedImage {
 public:
  PixelatedImage() = default;

  explicit PixelatedImage(const Size &size)
      : size_{size}, pixels_(size_.rows * size_.cols, ftxui::Color{}) {}

  PixelatedImage(int rows, int cols) : PixelatedImage{Size{rows, cols}} {}

  inline ftxui::Color &at(int row, int col) { return pixels_[Index(row, col)]; }
  inline const ftxui::Color &at(int row, int col) const {
    return pixels_[Index(row, col)];
  }

  inline const Size &size() const noexcept { return size_; }
  inline int cols() const noexcept { return size_.cols; }
  inline int rows() const noexcept { return size_.rows; }
  inline bool empty() const noexcept {
    return (size_.cols < 1) || (size_.rows < 1);
  }

 private:
  inline std::size_t Index(int row, int col) const {
    return row * size_.cols + col;
  }

  Size size_{};
  std::vector<ftxui::Color> pixels_{};
};

}  // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATED_IMAGE_HPP \
        */
