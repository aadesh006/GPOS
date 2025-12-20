ORG 0x7c00
BITS 16

_start:
    jmp short start
    nop

 times 33 db 0

start:
    jmp 0: step2


step2:
    cli:;Clears Interruptts
    mov ax, 0x00
    mov ds, ax
    mov es,ax
    mov ss, ax
    mov sp, 0x7c00
    sti: ;Enable Interruptts

    jmp $

.load_protected:
    cli
    lgdt[gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax

;GDT
gdt_start:
gdt_null:
    dd 0x0
    dd 0x0

;offset 0x0
gdt_code:
    dw 0xffff
    dw 0
    db 0
    db 0x9a
    bd 11001111b
    db 0
; offset 0x10
gdt_data:
    dw 0xffff
    dw 0
    db 0
    db 0x92
    bd 11001111b
    db 0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

[BITS 32]
load 32:

times 510-($-$$) db 0
dw 0xAA55
