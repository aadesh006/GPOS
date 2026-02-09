#include "shell.h"
#include "../kernel.h"
#include "../memory/memory.h"
#include "../terminal/terminal.h"

int strcmp(const char* a, const char* b)
{
    while (*a && *b && *a == *b)
    {
        a++; b++;
    }
    return *a - *b;
}

void shell_execute(const char* cmd)
{
    if (strcmp(cmd, "help") == 0)
    {
        print("Commands:\n");
        print(" help\n clear\n echo\n");
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        terminal_intialize();
    }
    else if (strcmp(cmd, "echo") == 0)
    {
        print("echo\n");
    }
    else
    {
        print("Unknown command\n");
    }
}