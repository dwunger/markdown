#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "markdown.h"


size_t get_file_size(const FILE *stream);
size_t count(const char *str, size_t str_len, char );
int main(int argc, char *argv[])
{
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
    
    size_t line_count = count(contents, file_size, '\n');
    for (size_t line_number = 0; line_number < line_count; line_number++)
    {
        // Iterate over lines
    }
    /* free file buffer */
    free(contents);
    return 0;
}

size_t get_file_size(FILE *stream)
{
    // Save cursor position
    long store_position = 0;
    store_position = ftell(stream);
    
    // Move cursor to start of file
    fseek(stream, 0, SEEK_SET);
    size_t fstart = ftell(stream);

    // Advance cursor to EOF
    fseek(stream, 0, SEEK_END);
    size_t fend = ftell(stream);
    
    // Restore cursor position
    fseek(stream, store_position, SEEK_SET);

    return (size_t)(fend - fstart);
}
