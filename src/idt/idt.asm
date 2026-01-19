section .asm

global idt_load
idt_load:
    push ebp
    mov ebp, esp
    mov ebx, [ebp+8]
    lidt [ebx]
    pop ebp
    ret
    
section .asm

global isr0
extern isr0_handler

isr0:
    cli
    pushad
    call isr0_handler
    popad
    sti
    iret
