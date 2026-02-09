#ifndef LINE_H
#define LINE_H

#define LINE_MAX 256

void line_reset();
int  line_feed(char c);   // returns 1 when line complete
const char* line_get();

#endif