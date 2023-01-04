#include <gtest/gtest.h>
#include <no_strings_attached/string_split.h>

namespace {
using no_strings_attached::Split;
}

TEST(SplitTest, SplitDelimeterNotFound) {
  const auto split_on_empty = Split("", " ");
  ASSERT_FALSE(split_on_empty.empty());
  EXPECT_EQ("", split_on_empty.front());
  const auto split_no_space = Split("hello", " ");
  ASSERT_FALSE(split_no_space.empty());
  EXPECT_EQ("hello", split_no_space.front());
}

TEST(SplitTest, SplitTwoWordsOnString) {
  const auto split = Split("hello world", " ");
  ASSERT_EQ(2UL, split.size());
  EXPECT_EQ("hello", split.front());
  EXPECT_EQ("world", split.back());
}

TEST(SplitTest, SplitMoreWords) {
  const auto split = Split("some_string__split__with_underscores", "__");
  ASSERT_EQ(3UL, split.size());
  EXPECT_EQ("some_string", split[0]);
  EXPECT_EQ("split", split[1]);
  EXPECT_EQ("with_underscores", split[2]);
}

TEST(SplitTest, RepeatedString) {
  const auto test_string = "split_me__and_me";
  const auto split = Split(test_string, "_");
  ASSERT_EQ(5UL, split.size());
  EXPECT_EQ("split", split[0]);
  EXPECT_EQ("me", split[1]);
  EXPECT_EQ("", split[2]);
  EXPECT_EQ("and", split[3]);
  EXPECT_EQ("me", split[4]);
}
