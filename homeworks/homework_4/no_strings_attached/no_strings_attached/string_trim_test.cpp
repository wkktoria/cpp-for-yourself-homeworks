#include <gtest/gtest.h>
#include <no_strings_attached/string_trim.h>

#include <string>

namespace {
using no_strings_attached::Side;
using no_strings_attached::Trim;
} // namespace

TEST(StringTrimTest, TrimWhitespaceFromLeft) {
  const std::string kExpected{"hello "};
  std::string result{Trim("  hello ", ' ', Side::kLeft)};

  EXPECT_EQ(result, kExpected);
}

TEST(StringTrimTest, TrimWhitespaceFromRight) {
  const std::string kExpected{"  hello"};
  std::string result{Trim("  hello ", ' ', Side::kRight)};

  EXPECT_EQ(result, kExpected);
}

TEST(StringTrimTest, TrimWhitespaceFromBothSides) {
  const std::string kExpected{"hello"};
  std::string result{Trim("  hello ", ' ', Side::kBoth)};

  EXPECT_EQ(result, kExpected);
}

TEST(StringTrimTest, TrimLetterFromLeft) {
  const std::string kExpected{"ello"};
  std::string result{Trim("hello", 'h', Side::kLeft)};

  EXPECT_EQ(result, kExpected);
}

TEST(StringTrimTest, TrimWhitespaceFromBothSidesByDefault) {
  const std::string kExpected{"hello"};
  std::string result{Trim("  hello ")};

  EXPECT_EQ(result, kExpected);
}