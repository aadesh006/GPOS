#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stddef.h>

void terminal_intialize();
void terminal_writechar(char c, char colour);
void terminal_backspace();

void print(const char* str);

#endif