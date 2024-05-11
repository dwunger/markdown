#include <gtest/gtest.h>

extern "C" {
#include <stdio.h>
#include "file.h"
}

TEST(File, get_file_size) {
    FILE * f = fopen("./src/example.md", "r");
    EXPECT_EQ(get_file_size(f), 1190);
    f = NULL;    
    EXPECT_EQ(get_file_size(f), 0);
}
