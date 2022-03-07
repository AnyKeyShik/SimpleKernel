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

# Folders
LIBC_SRCDIR := $(LIBDIR)/$(LIBC_DIR)

# Flags
ifeq ($(DEBUG),1)
LIBC_CFLAGS := -fno-stack-protector -fPIC -Werror -Wno-builtin-declaration-mismatch -m32 -g -c -I$(GLOBAL_INCLUDE) -o
else
LIBC_CFLAGS := -fno-stack-protector -fPIC -Werror -Wno-builtin-declaration-mismatch -m32 -c -I$(GLOBAL_INCLUDE) -o
endif
LIBC_LFLAGS := -g -shared -m32

# Sources and objects lists
LIBC_SOURCES := $(LIBC_SRCDIR)/string.c
LIBC_OBJECTS := $(patsubst $(LIBC_SRCDIR)/%, $(BUILDDIR)/%, $(LIBC_SOURCES:.$(SRCTEXT)=_c.o))

$(BUILDDIR)/%_c.o: $(LIBC_SRCDIR)/%.$(SRCTEXT)
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling c parts of $(LIBC_TARGET)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(LIBC_CFLAGS) $@ $<

$(LIBC_TARGET): $(LIBC_OBJECTS)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo "Linking..."
	$(V)echo -e "\tLinking $(LIBC_TARGET)"; $(CC) $(LIBC_LFLAGS) -o $@ $(LIBC_OBJECTS)