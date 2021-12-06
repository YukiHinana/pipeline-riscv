CC = riscv32-unknown-elf-gcc
OBJDUMP = riscv32-unknown-elf-objdump
OBJCOPY = riscv32-unknown-elf-objcopy
LD = riscv32-unknown-elf-ld

SRCS = pow.c 
OBJS = $(patsubst %.c, %.o, $(SRCS))


all: a.bin

entry.o: entry.s
	$(CC) -c $^ -o $@

%.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -rf *.o

a.elf: $(OBJS) entry.o linker.ld
	$(LD) --gc-sections -T linker.ld $(OBJS) entry.o -o $@

a.bin: a.elf
	$(OBJCOPY) --only-section=.raw -O binary $^ $@
	$(OBJDUMP) --disassemble $^ > a.dump


.PHONY: clean all

