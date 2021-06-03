MAKE_DIR	= $(shell pwd)

# Cross-Compiler
CC		= gcc

# Headers
inc		= $(MAKE_DIR)/include
# Blocks
panagram	= $(MAKE_DIR)/panagram
calculator	= $(MAKE_DIR)/calculator
# Binaries location
bin		= $(MAKE_DIR)/bin

# Documentation
docs		= $(MAKE_DIR)/docs

# C flags
debug		= -DDEBUG
optimize	= 3
stripping	= -s
GDEBUG		= -g3

CFLAGS		= $(debug) -c $(GDEBUG) -O$(optimize) -ffunction-sections -fdata-sections -fno-common
CFLAGS		+= -fstack-protector-strong -fstack-protector-all -o
WFLAGS		= -Wall -Wextra -Wpedantic -Werror
WFLAGS		+= -Wwrite-strings -Winline -Wnested-externs -Wcast-align -Wcast-qual -Wshadow -Wstrict-prototypes
WFLAGS		= -Wstack-usage=2097152 -Wundef
IFLAGS		= -I$(inc)
LFLAGS  	?=

# MAKE flags
MFLAGS		= -s
MFLAGS		+= -j$(shell nproc)
MFLAGS		+= -C

