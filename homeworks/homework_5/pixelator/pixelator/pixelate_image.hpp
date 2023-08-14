#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATE_IMAGE_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATE_IMAGE_HPP

#include "tui_pixelator/image.hpp"
#include "tui_pixelator/stb_image_data_view.hpp"

namespace pixelator {

Image PixelateImage(const StbImageDataView &image, Size smaller_size);

}  // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATE_IMAGE_HPP */
