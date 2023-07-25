#include "tui_pixelator/stb_image.hpp"

#include <gtest/gtest.h>

namespace {
using pixelator::StbImage;
}  // namespace

TEST(StbImageTest, Initialization) {
  const std::filesystem::path image_path{
      "../../tui_pixelator/test_data/grumpy.png"};
  const StbImage image{image_path};
  ASSERT_FALSE(image.empty());
  ASSERT_EQ(image.rows(), 686);
  ASSERT_EQ(image.cols(), 920);
}

TEST(StbImageTest, MoveConstructor) {
  const std::filesystem::path image_path{
      "../../tui_pixelator/test_data/grumpy.png"};
  StbImage image{image_path};
  ASSERT_FALSE(image.empty());
  const StbImage image_other{std::move(image)};
  ASSERT_TRUE(image.empty());
  ASSERT_FALSE(image_other.empty());
}

TEST(StbImageTest, MoveAssignmentOperator) {
  const std::filesystem::path image_path{
      "../../tui_pixelator/test_data/grumpy.png"};
  StbImage image_to_move_to{};
  ASSERT_TRUE(image_to_move_to.empty());
  StbImage image{image_path};
  image_to_move_to = std::move(image);
  ASSERT_TRUE(image.empty());
  ASSERT_FALSE(image_to_move_to.empty());
}
