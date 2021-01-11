CXX =	i686-elf-g++
GCC =	i686-elf-gcc
LD =	$(GCC)
AS = 	i686-elf-as

## ^^ stdflags

GCCPLAN =  i686-elf
LDFLAGS = -T
LDX = -ffreestanding -O2 -nostdlib -lgcc -nostdlib
CXXFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

APP = KiwifruitOS

CXX_RAW_OBJS = \
	./Kernel/kernel.cpp \

ASM_OBJS = \
	./bin/boot.o

OBJS = \
	./bin/kernel.o \

all: $(APP)

$(APP): $(OBJS)
		@echo "LD $@"; $(LD) $(LDFLAGS) Kernel/Linker.ld -o KiwifruitOS.bin $(LDX) bin/kernel.o bin/kiwiboot.o -lgcc

