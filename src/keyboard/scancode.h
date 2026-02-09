#ifndef SCANCODE_H
#define SCANCODE_H

static const char scancode_to_ascii[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', // 0x00
    '9', '0', '-', '=', '\b',                      // Backspace
    '\t',                                           // Tab
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
    '[', ']', '\n',                                 // Enter
    0,                                              // Control
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
    ';', '\'', '`',
    0,                                              // Left Shift
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
    ',', '.', '/',
    0,                                              // Right Shift
    '*',
    0,                                              // Alt
    ' ',                                            // Space
};
#endif
