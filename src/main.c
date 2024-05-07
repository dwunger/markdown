#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "markdown.h"


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
    char *contents = malloc(sizeof(char) * get_file_size(file_ptr));
    fread(contents, sizeof(char), get_file_size(file_ptr), file_ptr);


    /* free file buffer */
    free(contents);
    return 0;
}

