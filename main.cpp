#include <stdio.h>
#include "line.h"

typedef struct {
   FILE *fp;
   char *line;
   int cap;
} OpenLine;

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "使い方: %s ファイル名1 ファイル名2\n", argv[0]);
        return 1;
    }

    Line l1(argv[1], 32);
    Line l2(argv[2], 32);

	OpenLine *o1 = (OpenLine *)&l1;
	OpenLine *o2 = (OpenLine *)&l2;

    while ((l1.get_line()) != NULL) {
        printf("%s\n", o1->line);
    }

    while ((l2.get_line()) != NULL) {
        printf("%s\n", o2->line);
    }

    return 0;
}
