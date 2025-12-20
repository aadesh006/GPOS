# 1. Connect to QEMU using i386 (Standard PC) to avoid 64-bit packet errors
target remote | qemu-system-i386 -hda ./boot.bin -S -gdb stdio

# 2. NOW tell GDB we are in 16-bit mode
set architecture i8086

# 3. Show Assembly immediately
layout asm