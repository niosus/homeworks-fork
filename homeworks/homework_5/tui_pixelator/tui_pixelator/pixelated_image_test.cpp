#include "tui_pixelator/pixelated_image.hpp"

#include <gtest/gtest.h>

namespace {
using pixelator::PixelatedImage;
using pixelator::Size;
}  // namespace

TEST(PixelatedImageTest, DefaultConstructor) {
  PixelatedImage image;
  EXPECT_EQ(image.size().cols, 0);
  EXPECT_EQ(image.size().rows, 0);
  EXPECT_EQ(image.cols(), 0);
  EXPECT_EQ(image.rows(), 0);
}

TEST(PixelatedImageTest, ConstructorWithSize) {
  PixelatedImage image{Size{10, 20}};
  EXPECT_EQ(image.size().rows, 10);
  EXPECT_EQ(image.size().cols, 20);
  EXPECT_EQ(image.cols(), 20);
  EXPECT_EQ(image.rows(), 10);
}

TEST(PixelatedImageTest, AtMethod) {
  PixelatedImage image{Size{10, 20}};
  image.at(0, 0) = ftxui::Color::Red;
  EXPECT_EQ(image.at(0, 0), ftxui::Color::Red);
}
