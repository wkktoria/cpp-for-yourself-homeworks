#include <gtest/gtest.h>
#include <no_strings_attached/string_split.h>

#include <string>
#include <vector>

namespace {
using no_strings_attached::Split;
}

TEST(StringSplitTest, SplitWordsOnWhitespace) {
  const std::vector<std::string> kExpected{"hello", "world"};
  auto result{Split("hello world", " ")};

  EXPECT_EQ(result, kExpected);
}

TEST(StringSplitTest, SplitWordsOnString) {
  const std::vector<std::string> kExpected{"", "ab", "ba"};
  auto result{Split("aaabaaba", "aa")};

  EXPECT_EQ(result, kExpected);
}

TEST(StringSplitTest, SplitWordsOnWhitespaceAndKeepOnePart) {
  const int kPartsToKeep{1};
  const std::vector<std::string> kExpected{"hello"};
  auto result{Split("hello world", " ", kPartsToKeep)};

  EXPECT_EQ(result, kExpected);
  EXPECT_EQ(result.size(), kPartsToKeep);
}

TEST(StringSplitTest, SplitWordsOnWhitespaceAndKeepTwoParts) {
  const int kPartsToKeep{2};
  const std::vector<std::string> kExpected{"hello", "world"};
  auto result{Split("hello world", " ", kPartsToKeep)};

  EXPECT_EQ(result, kExpected);
  EXPECT_EQ(result.size(), kPartsToKeep);
}

TEST(StringSplitTest, SplitWordsOnStringAndKeepTwoParts) {
  const int kPartsToKeep{2};
  const std::vector<std::string> kExpected{"", "ab"};
  auto result{Split("aaabaaba", "aa", kPartsToKeep)};

  EXPECT_EQ(result, kExpected);
  EXPECT_EQ(result.size(), kPartsToKeep);
}