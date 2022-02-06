# Copyright (c) 2022. AnyKeyShik Rarity
#
# nikitav59@gmail.com
#
# https://t.me/AnyKeyShik

#
# Makefile fragment for the Simple Kernel.
# This is NOT a complete makefile;
# you must run GNU make in the top-level directory
# where the Makefile is located.
#

# Architecture defines
arch ?= x86

# Folders
SRCDIR := $(SRCDIR)arch/$(arch)
INCLUDEDIR := $(INCLUDEDIR)arch/$(arch)

# Flags
CFLAGS := -fno-stack-protector -nostdinc -O0 -m32 -c -I $(INCLUDEDIR) -o
NFLAGS := -felf
LFLAGS := -m elf_i386 --nmagic -T

# Sources and objects lists
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCTEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCTEXT)=_c.o))
ASM_SOURCES := $(shell find $(SRCDIR) -type f -name *.$(ASMTEXT))
ASM_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(ASM_SOURCES:.$(ASMTEXT)=_asm.o))

# Sub dirs
SUBDIRS := {boot,keyboard,screen}

$(BUILDDIR)/%_c.o: $(SRCDIR)/%.$(SRCTEXT)
	$(V)mkdir -p $(BUILDDIR)/$(SUBDIRS)
	$(V)echo "Compiling c parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(CFLAGS) $@ $<

$(BUILDDIR)/%_asm.o: $(SRCDIR)/%.$(ASMTEXT)
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling asm parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(ASM) $(NFLAGS) $< -o $@

$(TARGET): $(OBJECTS) $(ASM_OBJECTS)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo "Linking..."
	$(V)echo -e "\tLinking $(TARGET)"; $(LNK) $(LFLAGS) $(LNKDIR)/link.$(LNKTEXT) -o $@ $(OBJECTS) $(ASM_OBJECTS)