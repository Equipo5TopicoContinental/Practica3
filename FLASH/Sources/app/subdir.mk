################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/app/Buttons.c" \
"../Sources/app/Player.c" \
"../Sources/app/Player_Fsm.c" \
"../Sources/app/RGB_LEDs.c" \

C_SRCS += \
../Sources/app/Buttons.c \
../Sources/app/Player.c \
../Sources/app/Player_Fsm.c \
../Sources/app/RGB_LEDs.c \

OBJS += \
./Sources/app/Buttons.o \
./Sources/app/Player.o \
./Sources/app/Player_Fsm.o \
./Sources/app/RGB_LEDs.o \

C_DEPS += \
./Sources/app/Buttons.d \
./Sources/app/Player.d \
./Sources/app/Player_Fsm.d \
./Sources/app/RGB_LEDs.d \

OBJS_QUOTED += \
"./Sources/app/Buttons.o" \
"./Sources/app/Player.o" \
"./Sources/app/Player_Fsm.o" \
"./Sources/app/RGB_LEDs.o" \

C_DEPS_QUOTED += \
"./Sources/app/Buttons.d" \
"./Sources/app/Player.d" \
"./Sources/app/Player_Fsm.d" \
"./Sources/app/RGB_LEDs.d" \

OBJS_OS_FORMAT += \
./Sources/app/Buttons.o \
./Sources/app/Player.o \
./Sources/app/Player_Fsm.o \
./Sources/app/RGB_LEDs.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/app/Buttons.o: ../Sources/app/Buttons.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/Buttons.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/Buttons.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/Player.o: ../Sources/app/Player.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/Player.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/Player.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/Player_Fsm.o: ../Sources/app/Player_Fsm.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/Player_Fsm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/Player_Fsm.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/RGB_LEDs.o: ../Sources/app/RGB_LEDs.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/RGB_LEDs.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/RGB_LEDs.o"
	@echo 'Finished building: $<'
	@echo ' '


