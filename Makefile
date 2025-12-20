all:
	nasm -f bin ./src/boot/boot.asm -o ./bin/boot.bin

make clean:
	rm -rf ./bin/boot.bin