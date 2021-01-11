AS = i686-elf-as

OBJS = \
	Boot.o

APP = Boot

all: $(APP)
	$(APP): $(OBJS)
		@echo "Build Boot $@";
	.S.o:
		@echo "ASM: $<"; $(AS) $< -o $@ 