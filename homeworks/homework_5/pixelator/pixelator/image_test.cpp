#include "pixelator/image.hpp"

#include "ftxui/screen/color.hpp"
#include "gtest/gtest.h"

namespace {
using pixelator::Image;
using pixelator::Size;
}  // namespace

TEST(ImageTest, DefaultConstructorCreatesAnEmptyImage) {
  const Image image;
  EXPECT_TRUE(image.empty());
  EXPECT_EQ(image.size().cols, 0);
  EXPECT_EQ(image.size().rows, 0);
  EXPECT_EQ(image.cols(), 0);
  EXPECT_EQ(image.rows(), 0);
}

TEST(ImageTest, ImageCreatedWithSizeHasCorrectSize) {
  const Image image{Size{10, 20}};
  EXPECT_EQ(image.size().rows, 10);
  EXPECT_EQ(image.size().cols, 20);
  EXPECT_EQ(image.cols(), 20);
  EXPECT_EQ(image.rows(), 10);
}

TEST(ImageTest, ImageCreatedWithSizeHasCorrectDefaultColor) {
  const Image image{Size{10, 20}};
  EXPECT_FALSE(image.empty());
  EXPECT_EQ(image.cols(), 20);
  EXPECT_EQ(image.rows(), 10);
  for (auto row = 0; row < image.rows(); ++row) {
    for (auto col = 0; col < image.cols(); ++col) {
      EXPECT_EQ(image.at(row, col), ftxui::Color{});
    }
  }
}

TEST(ImageTest, AtMethodSetsAndReturnsCorrectColor) {
  Image image{Size{10, 20}};
  image.at(0, 0) = ftxui::Color::Red;
  EXPECT_EQ(image.at(0, 0), ftxui::Color::Red);
}

TEST(ImageTest, CanBeConstructedByCopyingAnExistingImage) {
  Image image{Size{10, 20}};
  image.at(0, 0) = ftxui::Color::Red;
  EXPECT_EQ(image.at(0, 0), ftxui::Color::Red);

  const Image image_copy{image};
  EXPECT_EQ(image_copy.at(0, 0), ftxui::Color::Red);
}

TEST(ImageTest, CanBeConstructedByMovingAnExistingImage) {
  Image image{Size{10, 20}};
  image.at(0, 0) = ftxui::Color::Red;
  EXPECT_EQ(image.at(0, 0), ftxui::Color::Red);

  const Image image_copy{std::move(image)};
  EXPECT_EQ(image_copy.at(0, 0), ftxui::Color::Red);
}
