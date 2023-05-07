OUT=rewind-2440
OBJS=start.o main.o
# toolchain configs
TOOLCHAIN_PREFIX=arm-daren-eabi
TOOLCHAIN_HOME=/Volumes/Workspace/__Resources/cross-toolchains/$(TOOLCHAIN_PREFIX)/bin

CC=$(TOOLCHAIN_HOME)/$(TOOLCHAIN_PREFIX)-gcc
LD=$(TOOLCHAIN_HOME)/$(TOOLCHAIN_PREFIX)-ld
OBJCOPY=$(TOOLCHAIN_HOME)/$(TOOLCHAIN_PREFIX)-objcopy
OBJDUMP=$(TOOLCHAIN_HOME)/$(TOOLCHAIN_PREFIX)-objdump

CFLAGS=-c
AFLAGS=-c
LDFLAGS=-Ttext 0
ALL = $(OUT).elf $(OUT).bin $(OUT).dis

all:	$(ALL)

$(OUT).elf: $(OBJS)
	$(LD) $(LDFLAGS) -g $(OBJS) -o $(OUT).elf
$(OUT).bin: $(OUT).elf
	$(OBJCOPY) -O binary $(OUT).elf $(OUT).bin
$(OUT).dis: $(OUT).elf
	$(OBJDUMP) -s -d $(OUT).elf > $(OUT).dis
%.o:	%.S
	$(CC) $(AFLAGS) -o $@ $<
%.o:	%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm *.o *.bin *.dis *.elf
