#include <stdio.h>

size_t get_file_size(const FILE *stream)
{
    if (stream == NULL) {
        return 0;
    }
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
