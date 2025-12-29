#include "kernel.h"
#include <stdint.h>

uint16_t* video_mem = 0;

uint16_t terminal_make_char(char c, char colour)
{
    return (colour << 8) | c;
}

void terminal_intialize(){
    video_mem = (int16_t*)(0xB8000);
    for (int y =0; y < VGA_HEIGHT; y++)
    {
        for(int x = 0; x<VGA_WIDTH; x++)
        {
            video_mem[(y*VGA_WIDTH) + x] = terminal_make_char(' ', 0);
        }
        
    }
}


void kernel_main()
{
    video_mem[0] = terminal_make_char('B',3);

}