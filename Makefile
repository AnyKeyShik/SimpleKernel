# Copyright (c) 2022. AnyKeyShik Rarity
#
# nikitav59@gmail.com
#
# https://t.me/AnyKeyShik

# Run 'make V=1' to turn on verbose commands, or 'make V=0' to turn them off.
ifeq ($(V),1)
override V =
endif
ifeq ($(V),0)
override V = @
endif

# try to infer the correct QEMU
ifndef QEMU
QEMU := $(shell if which qemu > /dev/null 2>&1; \
	then echo qemu; exit; \
	elif which qemu-system-i386 > /dev/null 2>&1; \
	then echo qemu-system-i386; exit; \
	else \
	qemu=/Applications/Q.app/Contents/MacOS/i386-softmmu.app/Contents/MacOS/i386-softmmu; \
	if test -x $$qemu; then echo $$qemu; exit; fi; fi; \
	echo "***" 1>&2; \
	echo "*** Error: Couldn't find a working QEMU executable." 1>&2; \
	echo "*** Is the directory containing the qemu binary in your PATH" 1>&2; \
	echo "*** or have you tried setting the QEMU variable in conf/env.mk?" 1>&2; \
	echo "***" 1>&2; exit 1)
endif

-include conf/env.mk

# CC
CC := gcc
ASM := nasm
LNK := ld
AR := ar

# Folders
KERDIR := kernel
LIBDIR := lib
INCLUDE := include
BOOTDIR := boot
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := kernel
LIBC := libc.so
LIBK := libk.a
ISOIM := kernel.iso

TARGET := $(TARGETDIR)/$(EXECUTABLE)
LIBC_TARGET := $(TARGETDIR)/$(LIBC)
LIBK_TARGET := $(BUILDDIR)/$(LIBK)
ISO := $(ISOIM)

QEMUOPTS := -serial mon:stdio -display curses --enable-kvm -cpu qemu32 -m 512 -no-reboot -vga std

ifeq ($(DEBUG),1)
GDBPORT	:= $(shell expr `id -u` % 5000 + 25000)
override QEMUOPTS += -d -gdb tcp::$(GDBPORT) -S
endif

.PHONY: first all run iso distclean clean

first: all

run: $(LIBK_TARGET) $(TARGET)
ifeq ($(DEBUG),1)
	$(V)echo "Your debug port is $(GDBPORT)"
endif
	
	$(V)$(QEMU) $(QEMUOPTS) -append "console=ttyS0 nokaslr" -kernel $(TARGET)

all: $(ISO)
	$(V)$(QEMU) $(QEMUOPTS) -drive format=raw,media=cdrom,file=$<

iso $(ISO): $(LIBK_TARGET) $(TARGET)
	$(V)mkdir -p iso/boot/grub
	$(V)cp $(TARGET) iso/boot/
	$(V)cp $(BOOTDIR)/grub.cfg iso/boot/grub/
	$(V)grub-mkrescue -o $(ISO) iso
	$(V)rm -r iso

distclean:
	$(V)echo "Cleaning objects..."
	$(V)rm -rf $(BUILDDIR)

clean:
	$(V)echo "Cleaning all..."
	$(V)rm -rf $(BUILDDIR) $(TARGETDIR) $(ISO)

include $(LIBDIR)/Makefile

include $(KERDIR)/Makefile
