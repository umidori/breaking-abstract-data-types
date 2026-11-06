#ifndef __GET_LINE_H__
#define __GET_LINE_H__
#include <stdio.h>

class Line {
private:
   FILE *fp;
   char *line;
   int cap;
public:
   Line(char *fname, int cap);
   char *get_line();
   ~Line();
};

#endif
