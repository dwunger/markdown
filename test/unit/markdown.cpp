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
    const char *multiline_str = "Line 1\nLine 2\nLast Line";
    EXPECT_STREQ("Line 1\nLine 2\nLast Line", multiline_str);

    
    // Advance to next line
    size_t next_line_length = 0;
    next_line_length = next_line(&multiline_str);
    EXPECT_STREQ("Line 2\nLast Line", multiline_str);
    EXPECT_EQ(6, next_line_length);


    // Advance to last line
    next_line_length = 0;
    next_line_length = next_line(&multiline_str);
    EXPECT_STREQ("Last Line", multiline_str);
    EXPECT_EQ(9, next_line_length);

    // Attempt to overrun buffer
    next_line_length = 0;
    next_line_length = next_line(&multiline_str);
    EXPECT_STREQ("", multiline_str);
    EXPECT_EQ(0, next_line_length);

    // Get NULL signal if caller continues consumption
    next_line_length = 0;
    next_line_length = next_line(&multiline_str);
    EXPECT_EQ(NULL, multiline_str);
    EXPECT_EQ(0, next_line_length);
}
