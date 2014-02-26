################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Algebra.cpp \
../src/Buoy.cpp \
../src/Camera.cpp \
../src/Collision.cpp \
../src/Crate.cpp \
../src/Entity.cpp \
../src/Game.cpp \
../src/GameWindow.cpp \
../src/Goal.cpp \
../src/Group.cpp \
../src/Main.cpp \
../src/Material.cpp \
../src/Particle.cpp \
../src/Player.cpp \
../src/Primitive.cpp \
../src/Scene.cpp \
../src/Scene_lua.cpp \
../src/Skybox.cpp \
../src/SoundManager.cpp \
../src/Texture.cpp \
../src/Track.cpp \
../src/Water.cpp 

OBJS += \
./src/Algebra.o \
./src/Buoy.o \
./src/Camera.o \
./src/Collision.o \
./src/Crate.o \
./src/Entity.o \
./src/Game.o \
./src/GameWindow.o \
./src/Goal.o \
./src/Group.o \
./src/Main.o \
./src/Material.o \
./src/Particle.o \
./src/Player.o \
./src/Primitive.o \
./src/Scene.o \
./src/Scene_lua.o \
./src/Skybox.o \
./src/SoundManager.o \
./src/Texture.o \
./src/Track.o \
./src/Water.o 

CPP_DEPS += \
./src/Algebra.d \
./src/Buoy.d \
./src/Camera.d \
./src/Collision.d \
./src/Crate.d \
./src/Entity.d \
./src/Game.d \
./src/GameWindow.d \
./src/Goal.d \
./src/Group.d \
./src/Main.d \
./src/Material.d \
./src/Particle.d \
./src/Player.d \
./src/Primitive.d \
./src/Scene.d \
./src/Scene_lua.d \
./src/Skybox.d \
./src/SoundManager.d \
./src/Texture.d \
./src/Track.d \
./src/Water.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/sw/include/lua-5.2.2/src -I/usr/local/include -I/sw/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


