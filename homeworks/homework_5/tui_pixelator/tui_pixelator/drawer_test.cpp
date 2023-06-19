#include "tui_pixelator/drawer.hpp"

#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <gtest/gtest.h>

namespace {
using pixelator::Drawer;
}

TEST(DrawerTest, Initialization) {
  Drawer drawer{ftxui::Dimension::Fixed(42)};
  EXPECT_EQ(drawer.size().cols, 21);
  EXPECT_EQ(drawer.size().rows, 42);
  EXPECT_EQ(drawer.cols(), 21);
  EXPECT_EQ(drawer.rows(), 42);
}

TEST(DrawerTest, SetColor) {
  Drawer drawer{ftxui::Dimension::Fixed(42)};
  const auto &color = drawer.ColorAt(10, 10);
  EXPECT_EQ(color, ftxui::Color{});
  const ftxui::Color set_color{10, 20, 30};
  drawer.SetPixelColor(10, 10, set_color);
  EXPECT_EQ(drawer.ColorAt(10, 10), set_color);
}
