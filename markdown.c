#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ESC 27
#define EMPTY_LINE_PLACEHOLDER "\t"

char *user_strtok_r(char *str, char delim, char **save_ptr);
void print_osc(const char *label, const char *uri);
int contains_inline_link(const char *line);
char *extract_markdown_link_info(char *line, char *title, char *link);
int count_stylizers(char *line);
char *mdstyle_to_ansi(char *line);
void replace_consecutive_newlines(char *str);

typedef struct {
    char title[512];
    char url[512];
} LINK;

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
    test_file[] = "1\n2\n\n3\n\n\n0";

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

void print_osc(const char *label, const char *uri) {
    printf("%c]8;;%s%c\\%s%c]8;;%c\\", ESC, uri, ESC, label, ESC, ESC);
}

int contains_inline_link(const char *line) {

    // A handful of edge cases which should not be processed

    // Too short for valid link format
    if (strlen(line) < 5)
        return 0;

    // Early return for non-touching delimiters:
    // [Website Name] (https://www.example.com/)
    //               ^
    // Unexpected whitespace
    if (!strstr(line, "]("))
        return 0;

    // Why process empty links?
    if (strstr(line, "[]()"))
        return 0;

    char *temp_ptr;
    char format[5] = "[]()\0";
    for (int i = 0; i < 4; i++) {
        temp_ptr = strchr(line, format[i]);
        if (!temp_ptr) {
            return 0;
        }
        line = temp_ptr;
    }

    return 1;
}

char *extract_markdown_link_info(char *line, char *title, char *link) {
    char *temp_ptr;
    char *copy_tmp;
    temp_ptr = strstr(line, "](");
    copy_tmp = temp_ptr;

    if (!temp_ptr) {
        perror("extract_markdown_link_info: could not find anchor into markdown link");
    }

    int anchor_position = (temp_ptr - line);

    // Look forward and extract link into link
    // Step over closing bracket and open parenthesis
    int i;
    temp_ptr += 2;
    for (i = 0; temp_ptr[i] != ')'; i++) {
        link[i] = temp_ptr[i];
    }
    link[i] = '\0';

    // Reset temp_ptr to anchor position
    temp_ptr = copy_tmp;

    while (*temp_ptr != '[') {
        temp_ptr--;
    }
    temp_ptr++;

    for (i = 0; temp_ptr[i] != ']'; i++) {
        title[i] = temp_ptr[i];
    }
    title[i] = '\0';
    printf("title: %s\nlink: %s\n", title, link);

    // return pointer to end of markdown link
    temp_ptr = strchr(temp_ptr, ']');
    temp_ptr++;

    return temp_ptr;
}

int count_stylizers(char *line) {

    if (!strchr(line, '_') && !strchr(line, '*')) {
        return 0;
    }

}

char *mdstyle_to_ansi(char *line) {
    size_t len = strlen(line) + 1;
    char *buffer = malloc(len * sizeof(char));

}

void replace_consecutive_newlines(char *str) {
    char *read_ptr = str, *write_ptr = str;
    int newline_count = 0;
    while (*read_ptr) {
        if (*read_ptr == '\n') {
            newline_count++;
            if (newline_count == 2) {
                strcpy(write_ptr, "\n" EMPTY_LINE_PLACEHOLDER "\n");
                write_ptr += strlen("\n" EMPTY_LINE_PLACEHOLDER "\n");
                newline_count = 1;
            }
        } else {
            if (newline_count == 1) {
                *write_ptr++ = '\n';
            }
            *write_ptr++ = *read_ptr;
            newline_count = 0;
        }
        read_ptr++;
    }
    *write_ptr = '\0';
}

char *user_strtok_r(char *str, char delim, char **save_ptr) {

    if (str == NULL) {
        str = *save_ptr;
    }

    if (str == NULL || *str == '\0') {
        return NULL;
    }

    // Skip leading delimiters
    while (*str == delim) {
        str++;
    }

    if (*str == '\0') {
        return NULL;
    }

    char *start_token = str;

    // Find the next delimiter or the end of the string
    while (*str != delim && *str != '\0') {
        str++;
    }

    if (*str != '\0') {
        *str = '\0';
        str++;
    }

    *save_ptr = str;

    return start_token;
}
