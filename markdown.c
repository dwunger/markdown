#include <stdio.h>
#define LINK "https://example.com/"
#define ESC 27

void print_osc(const char *label, const char *uri) {
    printf("%c]8;;%s%c\\%s%c]8;;%c\\", ESC, uri, ESC, label, ESC, ESC);
}

int contains_inline_link(const char *line) {
    
    int len = strlen(line);
    char sequence[5] = "[]()"
    
    
    for (int i = 0; i < len; i++) {
        
    }
}

int main(int argc, char* argv[]) {
    
    // DEBUG INFO
    printf("Supplied argument count: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    // DEBUG INFO

    print_osc("Example Link", LINK);
    
    return 0;
}
