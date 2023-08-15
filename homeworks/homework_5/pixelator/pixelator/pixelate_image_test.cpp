#include "pixelator/pixelate_image.hpp"

#include "pixelator/image.hpp"
#include "pixelator/size.hpp"
#include "pixelator/stb_image_data_view.hpp"

#include "gtest/gtest.h"

namespace {
using pixelator::Image;
using pixelator::PixelateImage;
using pixelator::Size;
using pixelator::StbImageDataView;

const auto kImagePath{"../../pixelator/test_data/test.png"};
const auto kBlack{ftxui::Color::RGB(0, 0, 0)};
const auto kWhite{ftxui::Color::RGB(255, 255, 255)};
}  // namespace

TEST(PixelateTest, PassingSameOrBiggerSizeReturnsSameSizedImage) {
  const StbImageDataView image{kImagePath};
  const auto size = image.size();
  const auto pixelated_image = PixelateImage(image, size);
  const Size bigger_size{size.rows + 10, size.cols + 20};
  const auto pixelated_image_bigger = PixelateImage(image, bigger_size);
  ASSERT_FALSE(pixelated_image.empty());
  ASSERT_FALSE(pixelated_image_bigger.empty());
  ASSERT_EQ(image.rows(), pixelated_image.rows());
  ASSERT_EQ(image.cols(), pixelated_image.cols());
  ASSERT_EQ(image.rows(), pixelated_image_bigger.rows());
  ASSERT_EQ(image.cols(), pixelated_image_bigger.cols());
  for (auto row = 0; row < image.rows(); ++row) {
    for (auto col = 0; col < image.cols(); ++col) {
      EXPECT_EQ(image.at(row, col), pixelated_image.at(row, col));
      EXPECT_EQ(image.at(row, col), pixelated_image_bigger.at(row, col));
    }
  }
}

TEST(PixelateTest, PixelateSimpleTest6x4Image) {
  const StbImageDataView image{kImagePath};
  const auto pixelated_image = PixelateImage(image, Size{3, 2});
  EXPECT_EQ(pixelated_image.rows(), 3) << "Pixelated image has wrong size.";
  EXPECT_EQ(pixelated_image.cols(), 2) << "Pixelated image has wrong size.";

  ASSERT_EQ(pixelated_image.at(0, 0), kBlack)
      << "Pixelated image color is wrong.";
  ASSERT_EQ(pixelated_image.at(2, 1), kWhite)
      << "Pixelated image color is wrong.";
}
