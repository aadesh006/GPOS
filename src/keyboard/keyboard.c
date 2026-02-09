#include "keyboard.h"

static char buffer[KEYBOARD_BUFFER_SIZE];
static uint32_t head = 0;
static uint32_t tail = 0;

void keyboard_init()
{
    head = 0;
    tail = 0;
}

void keyboard_push(char c)
{
    uint32_t next = (head + 1) % KEYBOARD_BUFFER_SIZE;

    if (next == tail)
        return;

    buffer[head] = c;
    head = next;
}

bool keyboard_has_char()
{
    return head != tail;
}

char keyboard_pop()
{
    if (head == tail)
        return 0;

    char c = buffer[tail];
    tail = (tail + 1) % KEYBOARD_BUFFER_SIZE;
    return c;
}
