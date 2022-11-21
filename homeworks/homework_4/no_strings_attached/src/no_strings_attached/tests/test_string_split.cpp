#include <gtest/gtest.h>

#include <no_strings_attached/string_split.hpp>

namespace {
using no_strings_attached::Split;
}

TEST(Split, SplitDelimeterNotFound) {
  const auto split_on_empty = Split("", " ");
  ASSERT_FALSE(split_on_empty.empty());
  EXPECT_EQ("", split_on_empty.front());
  const auto split_no_space = Split("hello", " ");
  ASSERT_FALSE(split_no_space.empty());
  EXPECT_EQ("hello", split_no_space.front());
}

TEST(Split, SplitTwoWordsOnString) {
  const auto split = Split("hello world", " ");
  ASSERT_EQ(2UL, split.size());
  EXPECT_EQ("hello", split.front());
  EXPECT_EQ("world", split.back());
}

TEST(Split, SplitTwoWordsOnChar) {
  const auto split = Split("hello world", ' ');
  ASSERT_EQ(2UL, split.size());
  EXPECT_EQ("hello", split.front());
  EXPECT_EQ("world", split.back());
}

TEST(Split, SplitMoreWords) {
  const auto split = Split("some_string__split__with_underscores", "__");
  ASSERT_EQ(3UL, split.size());
  EXPECT_EQ("some_string", split[0]);
  EXPECT_EQ("split", split[1]);
  EXPECT_EQ("with_underscores", split[2]);
}

TEST(Split, RepeatedChar) {
  const auto split = Split("split_me__and_me", '_');
  ASSERT_EQ(5UL, split.size());
  EXPECT_EQ("split", split[0]);
  EXPECT_EQ("me", split[1]);
  EXPECT_EQ("", split[2]);
  EXPECT_EQ("and", split[3]);
  EXPECT_EQ("me", split[4]);
}
