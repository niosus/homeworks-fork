#include "tui_pixelator/pixelate.hpp"

#include <gtest/gtest.h>

#include "tui_pixelator/pixelated_image.hpp"
#include "tui_pixelator/stb_image.hpp"

namespace {
using pixelator::Pixelate;
using pixelator::PixelatedImage;
using pixelator::Size;
using pixelator::StbImage;

const auto kImagePath{"../../tui_pixelator/test_data/test.png"};
const auto kBlack{ftxui::Color::RGB(0, 0, 0)};
const auto kWhite{ftxui::Color::RGB(255, 255, 255)};
}  // namespace

TEST(PixelateTest, PassingSameSizeDoesNothing) {
  const StbImage image{kImagePath};
  const auto pixelated_image = Pixelate(image, image.size());
  EXPECT_TRUE(pixelated_image.empty());
}

TEST(PixelateTest, PixelateSimpleImage) {
  const StbImage image{kImagePath};
  const auto pixelated_image = Pixelate(image, Size{3, 2});
  EXPECT_EQ(pixelated_image.rows(), 3);
  EXPECT_EQ(pixelated_image.cols(), 2);

  ASSERT_EQ(pixelated_image.at(0, 0), kBlack);
  ASSERT_EQ(pixelated_image.at(2, 1), kWhite);
}
