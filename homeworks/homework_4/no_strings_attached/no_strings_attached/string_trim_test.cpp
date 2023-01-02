#include <gtest/gtest.h>
#include <no_strings_attached/string_trim.h>

namespace {
using no_strings_attached::Side;
using no_strings_attached::Trim;
}  // namespace

TEST(TrimValidationTest, TrimEmpty) {
  const auto test_string = "";
  const auto trimmed_both_sides = Trim(test_string);
  const auto trimmed_both_sides_explicit = Trim(test_string, ' ', Side::kBoth);
  const auto trimmed_left_side = Trim(test_string, ' ', Side::kLeft);
  const auto trimmed_right_side = Trim(test_string, ' ', Side::kRight);
  EXPECT_EQ(trimmed_both_sides, test_string);
  EXPECT_EQ(trimmed_both_sides_explicit, test_string);
  EXPECT_EQ(trimmed_left_side, test_string);
  EXPECT_EQ(trimmed_right_side, test_string);
}

TEST(TrimValidationTest, TrimTrivial) {
  const auto test_string = "hello";
  const auto trimmed_both_sides = Trim(test_string);
  const auto trimmed_both_sides_explicit = Trim(test_string, ' ', Side::kBoth);
  const auto trimmed_left_side = Trim(test_string, ' ', Side::kLeft);
  const auto trimmed_right_side = Trim(test_string, ' ', Side::kRight);
  EXPECT_EQ(trimmed_both_sides, test_string)
      << "Failed to trim string: '" << test_string << "'";
  EXPECT_EQ(trimmed_both_sides_explicit, test_string)
      << "Failed to trim string: '" << test_string << "'";
  EXPECT_EQ(trimmed_left_side, test_string)
      << "Failed to trim string: '" << test_string << "'";
  EXPECT_EQ(trimmed_right_side, test_string)
      << "Failed to trim string: '" << test_string << "'";
}

TEST(TrimValidationTest, TrimCorrect) {
  const auto test_string = "  hello ";
  const auto trimmed_both_sides = Trim(test_string);
  const auto trimmed_both_sides_explicit = Trim(test_string, ' ', Side::kBoth);
  const auto trimmed_left_side = Trim(test_string, ' ', Side::kLeft);
  const auto trimmed_right_side = Trim(test_string, ' ', Side::kRight);
  const auto expected_both_trimmed = "hello";
  EXPECT_EQ(trimmed_both_sides, expected_both_trimmed)
      << "Failed to trim string: '" << test_string << "'";
  EXPECT_EQ(trimmed_both_sides_explicit, expected_both_trimmed)
      << "Failed to trim string: '" << test_string << "'";
  const auto expected_left_trimmed = "hello ";
  EXPECT_EQ(trimmed_left_side, expected_left_trimmed)
      << "Failed to trim string: '" << test_string << "'";
  const auto expected_right_trimmed = "  hello";
  EXPECT_EQ(trimmed_right_side, expected_right_trimmed)
      << "Failed to trim string: '" << test_string << "'";
}
