# GPOS - 32-bit Operating System

A custom 32-bit operating system built from scratch, featuring a bootloader, kernel, interrupt handling, and memory management. This project is designed to support file systems and multitasking capabilities.

## Features

- **Custom Bootloader**: Written in x86 assembly, handles the transition from 16-bit real mode to 32-bit protected mode
- **Protected Mode Kernel**: 32-bit kernel with proper GDT (Global Descriptor Table) configuration
- **Interrupt Descriptor Table (IDT)**: Basic interrupt handling system
- **VGA Text Mode**: Terminal output with 80x25 character display
- **Memory Management**: Basic memory operations (memset)
- **Modular Architecture**: Clean separation between bootloader, kernel, and subsystems

## Project Structure

```
.
├── bin/                    # Compiled binaries
├── build/                  # Intermediate build files
├── src/
│   ├── boot/
│   │   └── boot.asm       # Bootloader (16-bit → 32-bit transition)
│   ├── idt/
│   │   ├── idt.asm        # IDT assembly routines
│   │   ├── idt.c          # IDT implementation
│   │   └── idt.h          # IDT headers
│   ├── memory/
│   │   ├── memory.c       # Memory management functions
│   │   └── memory.h       # Memory headers
│   ├── kernel.asm         # Kernel entry point (assembly)
│   ├── kernel.c           # Main kernel code
│   ├── kernel.h           # Kernel headers
│   ├── config.h           # System configuration
│   └── linker.ld          # Linker script
├── build.sh               # Build script
├── Makefile               # Build configuration
└── .gdbinit              # GDB debugging configuration
```

## Prerequisites

- **Cross-compiler**: i686-elf-gcc and i686-elf-ld
- **NASM**: Netwide Assembler for x86 assembly
- **QEMU**: For testing and running the OS
- **GDB**: For debugging (optional)
- **Make**: Build automation tool

### Setting Up the Cross-Compiler

You'll need to build or install an i686-elf cross-compiler. The build script expects it to be located at `$HOME/opt/cross/bin/`.

Follow the [OSDev wiki guide](https://wiki.osdev.org/GCC_Cross-Compiler) to build your cross-compiler.

## Building

1. Clone the repository:
```bash
git clone https://github.com/aadesh006/GPOS.git
```

2. Make the build script executable:
```bash
chmod +x build.sh
```

3. Build the OS:
```bash
./build.sh
```

This will:
- Clean previous builds
- Compile all source files
- Link the kernel
- Create the bootable OS image at `./bin/os.bin`

## Running

### Using QEMU

```bash
qemu-system-i386 -hda ./bin/os.bin
```

### Debugging with GDB

The project includes a `.gdbinit` configuration for debugging:

```bash
gdb
```

This will automatically connect to QEMU and set up the debugging environment.

## Technical Details

### Boot Process

1. **BIOS loads bootloader** at 0x7C00 (512 bytes)
2. **Bootloader sets up GDT** with code and data segments
3. **Switches to 32-bit protected mode**
4. **Loads kernel from disk** using ATA LBA read (100 sectors at 0x100000)
5. **Jumps to kernel entry point**

### Memory Layout

- `0x7C00`: Bootloader location
- `0x100000` (1MB): Kernel load address
- `0x200000`: Stack pointer
- `0xB8000`: VGA text mode video memory

### Interrupt Handling

The IDT currently supports 512 interrupt vectors with basic handlers. The divide-by-zero interrupt (INT 0) is implemented as a proof of concept.

## Current Status

### Implemented
- Bootloader with protected mode transition
- Basic kernel with VGA text output
- GDT configuration
- IDT initialization
- Basic memory operations
- Terminal I/O functions

### In Progress / Planned
- File system support
- Multitasking/scheduling
- More interrupt handlers
- Keyboard input
- Heap memory allocator
- System calls

## Development

### Adding New Features

1. Create new source files in appropriate `src/` subdirectories
2. Add object file entries to `FILES` variable in Makefile
3. Add build rules following the existing pattern
4. Include headers in relevant files

### Code Style

- Assembly: NASM syntax
- C: GNU99 standard
- All code compiled with `-ffreestanding` (no standard library)

## Contributing

Contributions are welcome! Please feel free to submit issues and pull requests.

## Resources

- [OSDev.org](https://wiki.osdev.org/) - Comprehensive OS development wiki
- [Intel x86 Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html) - Processor documentation
- [NASM Documentation](https://www.nasm.us/docs.php) - Assembly reference


## Author

**Aadesh Chaudhari\
@aadesh006**

---

**Note**: This is an educational project for learning operating system development. It is not intended for production use.
