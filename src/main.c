#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "markdown.h"


int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Caller did not supply file path to program");
    }
    
    char *path;
    strcpy(path, argv[1]);
    
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {
        fprintf(stderr, "Out of memory");
    }
    char test_file[] = "1\n2\n\n3\n\n\n0";

    replace_consecutive_newlines(test_file);

    LINK link;
    char *stoken, *stok_save;
    char *ntoken, *ntok_save;

    // Split first by line, then by space 
    ntoken = user_strtok_r(test_file, '\n', &ntok_save);

    while (ntoken != NULL) {
        if (contains_inline_link(ntoken)) {
            extract_markdown_link_info(ntoken, link.title, link.url);
            print_osc(link.title, link.url);
        } else {
            stoken = user_strtok_r(ntoken, ' ', &stok_save);
            while (stoken != NULL) {
                printf("%s ", stoken);
                stoken = user_strtok_r(NULL, ' ', &stok_save);
            }
            printf("\n");
        }

        ntoken = user_strtok_r(NULL, '\n', &ntok_save);
    }

    return 0;
}
