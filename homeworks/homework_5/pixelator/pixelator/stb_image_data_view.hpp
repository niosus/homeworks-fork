#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_STB_IMAGE_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_STB_IMAGE_HPP

#include <algorithm>
#include <cstddef>
#include <filesystem>

#include "ftxui/screen/color.hpp"
#include "stb/stb_image.h"
#include "pixelator/size.hpp"

namespace pixelator {

class StbImageDataView {
 public:
  StbImageDataView() = default;
  explicit StbImageDataView(const std::filesystem::path& image_path);

  StbImageDataView(const StbImageDataView& other) = delete;
  StbImageDataView& operator=(const StbImageDataView& other) = delete;

  StbImageDataView(StbImageDataView&& other)
      : size_{other.size_},
        channels_{other.channels_},
        image_data_{other.image_data_} {
    other.image_data_ = nullptr;
  }

  StbImageDataView& operator=(StbImageDataView&& other) {
    if (&other == this) { return *this; }
    size_ = other.size_;
    channels_ = other.channels_;
    image_data_ = other.image_data_;
    other.image_data_ = nullptr;
    return *this;
  }

  ftxui::Color at(int row, int col) const;

  inline bool empty() const noexcept { return image_data_ == nullptr; }

  inline ~StbImageDataView() { stbi_image_free(image_data_); }

  inline const Size& size() const noexcept { return size_; }
  inline int cols() const noexcept { return size_.cols; }
  inline int rows() const noexcept { return size_.rows; }

 private:
  inline std::size_t StartIndex(int row, int col) const noexcept {
    return channels_ * (row * size_.cols + col);
  }

  Size size_{};
  int channels_{};
  std::uint8_t* image_data_{};
};

}  // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_STB_IMAGE_HPP */
