################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.o Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.su: ../Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.c Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Middleware/FreeRTOS" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Middleware/FreeRTOS/Source/include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Application/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Middleware-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d ./Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o ./Middleware/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Middleware-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

