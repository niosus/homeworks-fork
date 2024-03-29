#include "pixelator/pixelate_image.hpp"
#include "pixelator/image.hpp"
#include "pixelator/stb_image_data_view.hpp"

namespace {
int Scale(int number, float factor) {
  return static_cast<int>(number * factor);
}
}  // namespace

namespace pixelator {

Image PixelateImage(const StbImageDataView &image, Size smaller_size) {
  if ((smaller_size.cols > image.cols()) ||
      (smaller_size.rows > image.rows())) {
    smaller_size = image.size();
  }
  const auto factor_cols = smaller_size.cols / static_cast<float>(image.cols());
  const auto factor_rows = smaller_size.rows / static_cast<float>(image.rows());
  const auto smallest_factor = std::min(factor_cols, factor_rows);
  const Size new_smaller_size{Scale(image.rows(), smallest_factor),
                              Scale(image.cols(), smallest_factor)};
  Image pixelated_image{new_smaller_size};
  auto inverse_factor = 1.0F / smallest_factor;
  for (auto r = 0; r < pixelated_image.rows(); ++r) {
    const auto upscaled_row = Scale(r, inverse_factor);
    for (auto c = 0; c < pixelated_image.cols(); ++c) {
      const auto upscaled_col = Scale(c, inverse_factor);
      pixelated_image.at(r, c) = image.at(upscaled_row, upscaled_col);
    }
  }
  return pixelated_image;
}

}  // namespace pixelator
