#include "line.h"
#include <stdio.h>
#include <stdlib.h>

Line::Line(char *fname, int cap)
{
    if ((this->fp = fopen(fname, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    this->cap = cap;
    this->line = (char *)malloc(this->cap);
}

char *Line::get_line()
{
    int c;
    int n = 0;
    char *new_line;
    while ((c = fgetc(this->fp)) != EOF && c != '\n') {
        if (n >= this->cap - 1) {
            this->cap = this->cap * 2;
            new_line = (char *)realloc(this->line, this->cap);
            if (new_line == NULL) {
                perror("realloc");
                free(this->line);
                exit(1);
            }
            this->line = new_line;
        }
        this->line[n++] = c;
    }
    if (c == EOF && n == 0) {
        return NULL;
    }
    this->line[n] = '\0';
    return this->line;
}

Line::~Line()
{
    free(this->line);
    fclose(this->fp);
}
