#include <gtest/gtest.h>
extern "C" {
#include "markdown.h"
}

TEST(MarkdownTest, ContainsInlineLink) {
    EXPECT_EQ(contains_inline_link("[Website Name](https://www.example.com/)"), 1);
    EXPECT_EQ(contains_inline_link("No inline link"), 0);
}
