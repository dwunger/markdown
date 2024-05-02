#ifndef MARKDOWN_H 
#define MARKDOWN_H

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

#endif
