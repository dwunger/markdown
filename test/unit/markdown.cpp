#include <gtest/gtest.h>

extern "C" {
#include <stdbool.h>
#include "markdown.h"
}

TEST(MarkdownTest, ContainsInlineLink) {
    EXPECT_EQ(contains_inline_link("[Website Name](https://www.example.com/)"), 1);
    EXPECT_EQ(contains_inline_link("No inline link"), 0);
}

TEST(MarkdownTest, has_next_line) {
    EXPECT_EQ(has_next_line("Line 1\nLine 2\nLine 3"), true);
    EXPECT_EQ(has_next_line("Line 3"), false);
}

TEST(MarkdownTest, next_line) {
    char *multiline_str = "Line 1\nLine 2\nLine 3";
    // Do nothing
    EXPECT_STREQ("Line 1\nLine 2\nLine 3", multiline_str);
    // Advance to next line
    next_line(&multiline_str);
    EXPECT_STREQ("Line 2\nLine 3", multiline_str);
}
