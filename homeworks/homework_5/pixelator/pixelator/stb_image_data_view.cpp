#include "pixelator/stb_image_data_view.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace {
static constexpr auto kLoadAllChannels{0};
}

namespace pixelator {

StbImageDataView::StbImageDataView(const std::filesystem::path &image_path)
    : image_data_{stbi_load(image_path.c_str(),
                            &size_.cols,
                            &size_.rows,
                            &channels_,
                            kLoadAllChannels)} {}

ftxui::Color StbImageDataView::at(int row, int col) const {
  const auto start_index = StartIndex(row, col);
  return ftxui::Color::RGB(image_data_[start_index],
                           image_data_[start_index + 1],
                           image_data_[start_index + 2]);
}

}  // namespace pixelator
