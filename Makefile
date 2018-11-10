OBJECTS := obj/keyboard_map_c.o obj/kernel_c.o obj/kernel_asm.o

first: bin/kernel

obj:
	mkdir -p obj

bin:
	mkdir -p bin

obj/%.o: src/%.asm obj
	nasm -f elf32 $< -o $@

obj/%.o: src/%.c obj
	gcc -fno-stack-protector -m32 -c $< -o $@

bin/kernel: lnk/link.ld $(OBJECTS) bin
	ld -m elf_i386 -T $< -o $@ $(OBJECTS)

run: bin/kernel
	qemu-system-x86_64 -kernel $<

clean:
	rm -rf bin obj

.PHONY: run first clean
