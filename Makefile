OBJECTS := obj/keyboard_map_c.o obj/kernel_c.o obj/kernel_asm.o

first: bin/kernel

obj:
	mkdir -p obj

bin:
	mkdir -p bin

obj/%_asm.o: src/%.asm obj
	nasm -f elf32 $< -o $@

obj/%_c.o: src/%.c obj
	gcc -fno-stack-protector -m32 -c $< -o $@

bin/kernel: lnk/link.ld $(OBJECTS) bin
	ld -m elf_i386 -T $< -o $@ $(OBJECTS)

run: bin/kernel
	qemu-system-x86_64 -kernel $<

clean:
	rm -rf bin obj

old-install:
	cp bin/kernel /boot/kernel-01
	echo -e "title myKernel\n\troot (hd0,0)\n\tkernel /boot/kernel-01 ro" >> /boot/grub/grub.cfg

install:
	cp bin/kernel /boot/kernel-01
	echo -e "menuentry 'kernel 01' {\n\tset root='hd0,msdos1'\n\tmultiboot /boot/kernel-01 ro\n}" >> /boot/grub/grub.cfg

.PHONY: old-install install run first clean
