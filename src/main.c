#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "markdown.h"
#include "file.h"

char *get_line(const char *text, size_t line_number);
size_t count(const char *str, size_t str_len, char delimiter);

int main(int argc, char *argv[])
{
    /* Parse input args */
    if (argc < 2) {
        fprintf(stderr, "User must supply path to markdown file\n");
        exit(1);
    }
    
    /* Create a file object pointed at user's markdown file */
    FILE *file_ptr;
    file_ptr = fopen(argv[1], "r");

    /* Allocate space for file on heap */
    size_t file_size = get_file_size(file_ptr);
    char *contents = malloc(sizeof(char) * file_size);
    fread(contents, sizeof(char), file_size, file_ptr);
   
    
    /* Parse markdown file */
    const char *line = contents;
    size_t len = 0;
    char *mutable_copy; 
    while (has_next_line(line))
    {
        // Iterate over lines
        len = next_line(&line);
        mutable_copy = calloc(len + 1, sizeof(char));
        strncpy(mutable_copy, line, len);
        printf("%s\n",mutable_copy);

    }

    /* free file buffer */
    free(contents);
    return 0;
}

size_t count(const char *str, size_t str_len, char delimiter) {
    if (str == NULL) {
        perror("`count` received null pointer to str");
    }
    size_t count = 0;
    for (size_t idx = 0; idx < str_len; idx++) {
        if (str[idx] == delimiter) { count++; }
    }
    return count;
}

