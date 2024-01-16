#include <stdio.h>
#define LINK "https://example.com/"

int main (int argc, char* argv[]) {
    
    // DEBUG INFO
    printf("Supplied argument count: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    // DEBUG INFO

    printf("%c]8;;", 27);
    printf("%s%c\\Example Text%c]8;;%c\\", LINK, 27, 27, 27);
    
    return 0;
}

