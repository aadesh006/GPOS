#include "line.h"

static char line[LINE_MAX];
static int len = 0;

void line_reset()
{
    len = 0;
    line[0] = 0;
}

int line_feed(char c)
{
    if (c == '\n')
    {
        line[len] = 0;
        return 1; // line complete
    }

    if (c == '\b')
    {
        if (len > 0)
        {
            len--;
            line[len] = 0;
        }
        return 0;
    }

    if (len < LINE_MAX - 1)
    {
        line[len++] = c;
        line[len] = 0;
    }
    return 0;
}

const char* line_get()
{
    return line;
}
