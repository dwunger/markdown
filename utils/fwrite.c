
#define TEST_PAGE1 "# Markdown Features Showcase\n\nThis Markdown document will demonstrate various Markdown features, including:\n\n1. Headers\n2. Lists\n3. Emphasis and Strong emphasis\n4. Links\n5. Images\n6. Blockquotes\n7. Code blocks\n8. Horizontal rules\n\n## 1. Headers\n\nHeaders are created using the `#` symbol. There are six levels of headers, with one `#` for the largest and six `######` for the smallest.\n\n## 2. Lists\n\n### Unordered List\n\n- Item 1\n- Item 2\n  - Sub-item 2.1\n  - Sub-item 2.2\n\n### Ordered List\n\n1. First item\n2. Second item\n   1. Sub-item 2.1\n   2. Sub-item 2.2\n\n## 3. Emphasis and Strong emphasis\n\n*This text is italic.*\n**This text is bold.**\n\n## 4. Links\n\n[Example Website Link](https://www.example.com/)\n\n## 5. Images\n\n![Markdown Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/4/48/Markdown-mark.svg/1200px-Markdown-mark.svg.png)\n\n## 6. Blockquotes\n\n> This is a blockquote. You can use it to emphasize a quote or a section of text.\n\n## 7. Code blocks\n\n```python\ndef greet(name):\n    print(f\"Hello, {name}!\")\n```\n\n## 8. Horizontal rules\n\n---\nThis is a horizontal rule. It creates a visible separation between sections.\n\0"


#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    const char path[256] = "./example.md";

    file = fopen(path, "w+");
    
    if (file == NULL) {
        return 1;
    }

    fprintf(file, TEST_PAGE1);

    return 0;
}
