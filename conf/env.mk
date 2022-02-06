# env.mk - configuration variables for the JOS lab

# '$(V)' controls whether the lab makefiles print verbose commands (the
# actual shell commands run by Make), as well as the "overview" commands
# (such as '+ cc lib/readline.c').
#
# For overview commands only, the line should read 'V = @'.
# For overview and verbose commands, the line should read 'V ='.
V = @

# If the makefile cannot find your QEMU binary, uncomment the
# following line and set it to the full path to QEMU.
#
# QEMU=

# For debug purposes
DEBUG =