
all: markdown

markdown: markdown.c
	gcc markdown.c -o markdown

clean:
	rm -f markdown
