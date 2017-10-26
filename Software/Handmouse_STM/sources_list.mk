################################################################################
################################## Defines  ####################################
################################################################################

#CFLAGS += -D USE_USB_OTG_FS

################################################################################
##################################### Libs #####################################
################################################################################

LIBDIR += -L lib
#LIBDIR += -L Libraries/CMSIS/Lib
LIBDIR += -L Libraries/CMSIS/
#LIBDIR += -L /usr/lib

LDLIBS += -larm_cortexM0l_math
#LDLIBS += -larm_cortexM4l_math
#LDLIBS += -larm_cortexM4lf_math

################################################################################
################################## Includes ####################################
################################################################################


INCLUDEPATH += -I inc
INCLUDEPATH += -I .

INCLUDEPATH += -I Libraries/CMSIS/Include
INCLUDEPATH += -I Libraries/CMSIS/Device/ST/STM32F0xx/Include
INCLUDEPATH += -I Libraries/STM32F0xx_StdPeriph_Driver/inc
INCLUDEPATH += -I src/asserv

INCLUDEPATH += -I Utilities/STM32F0-Discovery


################################################################################
#################################  Sources  ####################################
################################################################################


### User
SRCC += src/main.c
SRCC += src/system_stm32f0xx.c
SRCC += src/hardware/gpio.c
SRCC += src/hardware/uart.c
#SRCC += src/gps.c
#SRCC += src/capteur_gp2.c
#SRCC += src/i2c_master.c
#SRCC += src/position_manager.c
#SRCC += src/asserv_manager.c
#SRCC += src/fxx.c
#SRCC += src/diff.c
#SRCC += src/pid.c
#SRCC += src/quadramp.c
#SRCC += src/control_system_manager.c
#SRCC += src/timer.c
#SRCC += src/servo.c
#SRCC += src/camera.c
#SRCC += src/trajectory_manager.c
#SRCC += src/modulo.c

###  STM32F4-Discovery
#SRCC += Utilities/STM32F4-Discovery/stm32f4_discovery.c


###  STM32F4xx_StdPeriph_Driver
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_usart.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_misc.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_gpio.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_rcc.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_syscfg.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_adc.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_i2c.c
SRCC += Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_tim.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c
#SRCC += Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c


################################################################################
################################### END ########################################
################################################################################

