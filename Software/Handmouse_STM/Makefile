#####################################
##    par Théotime Bollengier      ##
#####################################


NAME              = handmouse
OPTIMISATION      = s

#WARNINGS += 
#WARNINGS += -W  
WARNINGS += -W -Wall -lm

LD_FILE = fichier_conf/STM32F070x6_FLASH.ld
STARTUP = fichier_conf/startup_STM32F0xx


################################################################################
################################################################################
################################################################################

include sources_list.mk

.PHONY: all asm hex bin disasm size clean openocd telnet gdb gdbtui videbug flash opengdb opentelnet


#TC      = ~fabien/stm32_code/gcc-arm-none-eabi-4_7-2013q1/bin/arm-none-eabi
#TC      = /usr/local/bin/gcc-arm-none-eabi-4_7-2012q4/bin/arm-none-eabi
TC      = arm-none-eabi
CC      = $(TC)-gcc
LD      = $(TC)-gcc
AR      = $(TC)-ar
SIZE    = $(TC)-size
OBJCOPY = $(TC)-objcopy
OBJDUMP = $(TC)-objdump
GDB     = $(TC)-gdb

PROGRAM_NAME = build/$(NAME)

#COMMONFLAGS += -O$(OPTIMISATION) -mthumb -march=armv7e-m -mcpu=cortex-m4 -g
#COMMONFLAGS  += -O$(OPTIMISATION) -pipe -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -g
COMMONFLAGS += -O$(OPTIMISATION) -pipe -mthumb -march=armv7e-m -mcpu=cortex-m0 -mfloat-abi=soft -g

CFLAGS      += $(COMMONFLAGS) $(INCLUDEPATH) $(WARNINGS)

CFLAGS      += -D ARM_MATH_CM0
#CFLAGS      += -D __FPU_PRESENT=0
CFLAGS      += -D ARM_MATH_ROUNDING
#CFLAGS      += -D ARM_MATH_MATRIX_CHECK

CFLAGS      += -D USE_STDPERIPH_DRIVER
CFLAGS      += -D USE_ST_INIT_CLK
CFLAGS      += -D STM32F0XX
CFLAGS      += -D SERIAL_DEBUG



LDFLAGS += $(COMMONFLAGS) $(LIBDIR) -nostartfiles -Wl,-Map=./$(PROGRAM_NAME).map,-T$(LD_FILE)
#LDFLAGS += $(COMMONFLAGS) -fno-exceptions -ffunction-sections -fdata-sections -nostartfiles -Wl,--gc-sections,-Map=./$(PROGRAM_NAME).map,-T$(LD_FILE)

LDLIBS += -lm

LIBDIR += -L .


SRCC += $(wildcard *.c) 
SRCS += $(wildcard *.s)
#OBJS += $(SRCC:.cpp=.o) $(SRCS:.s=.o)
OBJS += $(SRCC:.c=.o) $(SRCS:.s=.o)
#ASM  += $(SRCC:.cpp=.s) 
ASM  += $(SRCC:.c=.s)

all: $(PROGRAM_NAME).hex
	@echo "Done"


################################################################################
############################### ELF output #####################################
################################################################################


$(PROGRAM_NAME).elf: $(OBJS) $(STARTUP).o
	@echo "Linking the project"
	@$(CC) -o $(PROGRAM_NAME).elf $(LDFLAGS) \
		$(OBJS) \
		$(STARTUP).o \
		-Wl,--no-whole-archive \
		$(LDLIBS)
	@echo "\033[0m" 
	$(SIZE) $(PROGRAM_NAME).elf

%.o : %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o : %.s
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -x assembler-with-cpp -c $< -o $@

$(STARTUP).o: $(STARTUP).c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c -O0 $< -o $@

disasm: $(PROGRAM_NAME).elf
	@echo "Disassembling elf file" 
	@$(OBJDUMP) -SDh $(PROGRAM_NAME).elf > $(PROGRAM_NAME).lss
	@echo "\033[0m" 


################################################################################
################################### ASM ########################################
################################################################################


asm: $(ASM)

%.s : %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -S $< -o $@


################################################################################
############################ HEX and BIN output ################################
################################################################################


hex: $(PROGRAM_NAME).hex 

$(PROGRAM_NAME).hex: $(PROGRAM_NAME).elf
	@echo "Creating hex file"
	@$(OBJCOPY) -O ihex $(PROGRAM_NAME).elf $@

bin: $(PROGRAM_NAME).bin

$(PROGRAM_NAME).bin: $(PROGRAM_NAME).elf
	@echo "Creating raw binary file"
	@$(OBJCOPY) -O binary $(PROGRAM_NAME).elf $@

size: $(PROGRAM_NAME).elf
	$(SIZE) $<


################################################################################
################################### Clean ######################################
################################################################################


clean:
	rm -fv $(OBJS) $(STARTUP).o
	rm -fv $(PROGRAM_NAME).hex
	rm -fv $(PROGRAM_NAME).bin 
	rm -fv $(PROGRAM_NAME).elf
	rm -fv $(PROGRAM_NAME).map
	rm -fv $(PROGRAM_NAME).lss

#	find . -name '*.o' -exec rm -v '{}' \;

################################################################################
################################ DEBUG FLASH ###################################
################################################################################


openocd:
	@echo "\033[1;36mOpenOCD\033[0m"
	openocd -f fichier_conf/openocd_stm32.cfg 

telnet:
	@echo "\033[1;36mTelnet\033[0m"
	telnet localhost 4444

gdb: $(PROGRAM_NAME).elf
	@echo "\033[1;36mDebug\033[0m"
	$(GDB) --eval-command="target remote localhost:3333" \
		$(PROGRAM_NAME).elf

gdbtui: $(PROGRAM_NAME).elf
	@echo "\033[1;36mDebug\033[0m"
	$(GDB)-tui --eval-command="target remote localhost:3333" \
		$(PROGRAM_NAME).elf


videbug: $(PROGRAM_NAME).elf
	@echo "\033[1;36mDebug\033[0m"
	pyclewn -e vim -p $(GDB) -a $(PROGRAM_NAME).elf

flash: $(PROGRAM_NAME).hex
	@echo "Flashing"
	openocd -f fichier_conf/openocd_stm32.cfg \
		-c "flash_target $(PROGRAM_NAME).hex" -c "exit 0"

reset: 
	@echo "\033[1;36mRESET\033[0m"
	openocd -f fichier_conf/openocd_stm32.cfg \
		-c "init" -c "reset run" -c "exit 0"


opentelnet: $(PROGRAM_NAME).elf
	@echo "\033[1;36mOpenOCD -> init, reset and halt\033[0m"
	@openocd -f fichier_conf/openocd_stm32.cfg -l /dev/null &
	@sleep 1
	@echo "\033[1;36mTelnet\033[0m"
	telnet localhost 4444
	@echo "\033[1;36mKilling OpenOCD\033[0m"
	@killall openocd
	@echo "\033[1;36mDone\033[0m"


tarball: backup_dir
	tar -czvf backup_dir/backup.tgz Makefile $(SRC) $(ASSM) 


backup_dir:
	@mkdir -p backup_dir


################################################################################
################################### END ########################################
################################################################################

