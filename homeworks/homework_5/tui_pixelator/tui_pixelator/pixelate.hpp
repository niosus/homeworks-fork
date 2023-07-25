#ifndef HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATE_HPP
#define HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATE_HPP

#include "tui_pixelator/pixelated_image.hpp"
#include "tui_pixelator/stb_image.hpp"

namespace pixelator {

PixelatedImage Pixelate(const StbImage &image, const Size &smaller_size);

}  // namespace pixelator

#endif /* HOMEWORKS_HOMEWORK_5_TUI_PIXELATOR_TUI_PIXELATOR_PIXELATE_HPP */
