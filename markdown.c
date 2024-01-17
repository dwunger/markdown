#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINK "https://example.com/"
#define ESC 27

void print_osc(const char *label, const char *uri) {
    printf("%c]8;;%s%c\\%s%c]8;;%c\\", ESC, uri, ESC, label, ESC, ESC);
}

int contains_inline_link(const char *line) {
    // Will use heuristics to determine a match
    // Using Dillinger Markdown as reference 
    
    int len = strlen(line);
    char sequence[5] = "[]()";
    
    // Satisfies minimum length requirement
    if (len < 4) {
        return 0;
    }

    // Test for presence of necessary characters
    for (int i = 0; i < 4; i++) {
        if (!strchr(line, sequence[i])) {
            return 0;
        }
    } 

    int closing_paren = 0;
    int closing_brack = 0;
    
    for (int i = 0; i < len; i++) {
        continue;   
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
