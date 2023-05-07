###########################################################################
## Makefile generated for component 'raspi_googlenet_trash_class'. 
## 
## Makefile     : raspi_googlenet_trash_class_rtw.mk
## Generated on : Mon Oct 17 15:55:31 2022
## Final product: $(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/raspi_googlenet_trash_class.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = raspi_googlenet_trash_class
MAKEFILE                  = raspi_googlenet_trash_class_rtw.mk
MATLAB_ROOT               = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2020b
MATLAB_BIN                = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = $(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/codegen/exe/raspi_googlenet_trash_class
TGT_FCN_LIB               = ISO_C++
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU GCC Raspberry Pi
# Supported Version(s):    
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

CCOUTPUTFLAG = --output_file=
LDOUTPUTFLAG = --output_file=

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm -lstdc++

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU GCC Raspberry Pi Assembler
AS = as

# C Compiler: GNU GCC Raspberry Pi C Compiler
CC = gcc

# Linker: GNU GCC Raspberry Pi Linker
LD = gcc

# C++ Compiler: GNU GCC Raspberry Pi C++ Compiler
CPP = g++

# C++ Linker: GNU GCC Raspberry Pi C++ Linker
CPP_LD = g++

# Archiver: GNU GCC Raspberry Pi Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = -r
ASFLAGS              = -c \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -O2
CPPFLAGS             = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -fpermissive  \
                       -O2
CPP_LDFLAGS          = -lrt -lpthread -ldl
CPP_SHAREDLIB_LDFLAGS  = -shared  \
                         -lrt -lpthread -ldl
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -lrt -lpthread -ldl
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared  \
                       -lrt -lpthread -ldl



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/raspi_googlenet_trash_class.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program -I$(MATLAB_ROOT)/toolbox/eml/externalDependency/timefun -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server -I$(ARM_COMPUTELIB) -I$(ARM_COMPUTELIB)/include -I$(START_DIR)/examples -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/include -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D_POSIX_C_SOURCE=199309L -D_MW_MATLABTGT_ -DUSE_19_05_LIBRARY -DMW_PWMBLOCK -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_MATLABTARGET
DEFINES_CUSTOM = 
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=200000
DEFINES_STANDARD = -DMODEL=raspi_googlenet_trash_class

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_WORKSPACE)/MWConcatenationLayer.cpp $(MATLAB_WORKSPACE)/MWElementwiseAffineLayer.cpp $(MATLAB_WORKSPACE)/MWFusedConvReLULayer.cpp $(MATLAB_WORKSPACE)/MWSplittingLayer.cpp $(MATLAB_WORKSPACE)/cnn_api.cpp $(MATLAB_WORKSPACE)/MWCNNLayerImpl.cpp $(MATLAB_WORKSPACE)/MWConcatenationLayerImpl.cpp $(MATLAB_WORKSPACE)/MWElementwiseAffineLayerImpl.cpp $(MATLAB_WORKSPACE)/MWFusedConvReLULayerImpl.cpp $(MATLAB_WORKSPACE)/MWSplittingLayerImpl.cpp $(MATLAB_WORKSPACE)/MWTargetNetworkImpl.cpp $(MATLAB_WORKSPACE)/MWACLUtils.cpp $(MATLAB_WORKSPACE)/MWCustomLayerForARMNEON.cpp $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_video_display.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/v4l2_cam.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/availableWebcam.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_pigs.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/system.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/devices.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/GPIO.c $(START_DIR)/raspi_googlenet_trash_class_main_terminate.cpp $(START_DIR)/raspi_googlenet_trash_class_data.cpp $(START_DIR)/rt_nonfinite.cpp $(START_DIR)/rtGetNaN.cpp $(START_DIR)/rtGetInf.cpp $(START_DIR)/raspi_googlenet_trash_class_initialize.cpp $(START_DIR)/raspi_googlenet_trash_class_terminate.cpp $(START_DIR)/raspi_googlenet_trash_class.cpp $(START_DIR)/DeepLearningNetwork.cpp $(START_DIR)/tic.cpp $(START_DIR)/toc.cpp $(START_DIR)/imresize.cpp $(START_DIR)/predict.cpp $(START_DIR)/postProcessOutputToReturnCategorical.cpp $(START_DIR)/strtrim.cpp $(START_DIR)/strcmp.cpp $(START_DIR)/sprintf.cpp $(START_DIR)/examples/main.cpp $(START_DIR)/insertionsort.cpp $(START_DIR)/introsort.cpp $(START_DIR)/insertText.cpp $(START_DIR)/SDLVideoDisplay.cpp $(START_DIR)/raspi.cpp $(START_DIR)/webcam.cpp $(START_DIR)/ServoBlock.cpp $(START_DIR)/categorical.cpp $(START_DIR)/GPIOCodegen.cpp $(START_DIR)/PWMBlock.cpp $(START_DIR)/SystemProp.cpp $(START_DIR)/ProcessConstructorArguments.cpp $(START_DIR)/PWMBase2.cpp $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_raspi_init.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/src/periphs/MW_Pyserver_control.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MWConcatenationLayer.cpp.o MWElementwiseAffineLayer.cpp.o MWFusedConvReLULayer.cpp.o MWSplittingLayer.cpp.o cnn_api.cpp.o MWCNNLayerImpl.cpp.o MWConcatenationLayerImpl.cpp.o MWElementwiseAffineLayerImpl.cpp.o MWFusedConvReLULayerImpl.cpp.o MWSplittingLayerImpl.cpp.o MWTargetNetworkImpl.cpp.o MWACLUtils.cpp.o MWCustomLayerForARMNEON.cpp.o MW_video_display.c.o v4l2_cam.c.o availableWebcam.c.o MW_pigs.c.o system.c.o devices.c.o GPIO.c.o raspi_googlenet_trash_class_main_terminate.cpp.o raspi_googlenet_trash_class_data.cpp.o rt_nonfinite.cpp.o rtGetNaN.cpp.o rtGetInf.cpp.o raspi_googlenet_trash_class_initialize.cpp.o raspi_googlenet_trash_class_terminate.cpp.o raspi_googlenet_trash_class.cpp.o DeepLearningNetwork.cpp.o tic.cpp.o toc.cpp.o imresize.cpp.o predict.cpp.o postProcessOutputToReturnCategorical.cpp.o strtrim.cpp.o strcmp.cpp.o sprintf.cpp.o main.cpp.o insertionsort.cpp.o introsort.cpp.o insertText.cpp.o SDLVideoDisplay.cpp.o raspi.cpp.o webcam.cpp.o ServoBlock.cpp.o categorical.cpp.o GPIOCodegen.cpp.o PWMBlock.cpp.o SystemProp.cpp.o ProcessConstructorArguments.cpp.o PWMBase2.cpp.o MW_raspi_init.c.o MW_Pyserver_control.c.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ =  -std=c++11  -mfpu=neon  -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ =  -std=c++11  -mfpu=neon  -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -L"$(ARM_COMPUTELIB)/lib" -rdynamic -larm_compute -larm_compute_core -Wl,-rpath,"$(ARM_COMPUTELIB)/lib":-L"$(ARM_COMPUTELIB)/lib"  -fopenmp -lpigpio
CPP_LDFLAGS_SKIPFORSIL = -lSDL

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -L"$(ARM_COMPUTELIB)/lib" -rdynamic -larm_compute -larm_compute_core -Wl,-rpath,"$(ARM_COMPUTELIB)/lib":-L"$(ARM_COMPUTELIB)/lib"  -fopenmp -lpigpio
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -lSDL

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_ = -L"$(ARM_COMPUTELIB)/lib" -rdynamic -larm_compute -larm_compute_core -Wl,-rpath,"$(ARM_COMPUTELIB)/lib":-L"$(ARM_COMPUTELIB)/lib"  -fopenmp -lpigpio
LDFLAGS_SKIPFORSIL = -lSDL

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -L"$(ARM_COMPUTELIB)/lib" -rdynamic -larm_compute -larm_compute_core -Wl,-rpath,"$(ARM_COMPUTELIB)/lib":-L"$(ARM_COMPUTELIB)/lib"  -fopenmp -lpigpio
SHAREDLIB_LDFLAGS_SKIPFORSIL = -lSDL

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/D/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/examples/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/examples/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/examples/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_video_display.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_video_display.c
	$(CC) $(CFLAGS) -o "$@" "$<"


v4l2_cam.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/v4l2_cam.c
	$(CC) $(CFLAGS) -o "$@" "$<"


availableWebcam.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/availableWebcam.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_pigs.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_pigs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/system.c
	$(CC) $(CFLAGS) -o "$@" "$<"


devices.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/devices.c
	$(CC) $(CFLAGS) -o "$@" "$<"


GPIO.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/GPIO.c
	$(CC) $(CFLAGS) -o "$@" "$<"


raspi_googlenet_trash_class_main_terminate.cpp.o : $(START_DIR)/raspi_googlenet_trash_class_main_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raspi_googlenet_trash_class_data.cpp.o : $(START_DIR)/raspi_googlenet_trash_class_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.cpp.o : $(START_DIR)/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.cpp.o : $(START_DIR)/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.cpp.o : $(START_DIR)/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raspi_googlenet_trash_class_initialize.cpp.o : $(START_DIR)/raspi_googlenet_trash_class_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raspi_googlenet_trash_class_terminate.cpp.o : $(START_DIR)/raspi_googlenet_trash_class_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raspi_googlenet_trash_class.cpp.o : $(START_DIR)/raspi_googlenet_trash_class.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


DeepLearningNetwork.cpp.o : $(START_DIR)/DeepLearningNetwork.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


tic.cpp.o : $(START_DIR)/tic.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


toc.cpp.o : $(START_DIR)/toc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imresize.cpp.o : $(START_DIR)/imresize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


predict.cpp.o : $(START_DIR)/predict.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


postProcessOutputToReturnCategorical.cpp.o : $(START_DIR)/postProcessOutputToReturnCategorical.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strtrim.cpp.o : $(START_DIR)/strtrim.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strcmp.cpp.o : $(START_DIR)/strcmp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sprintf.cpp.o : $(START_DIR)/sprintf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


main.cpp.o : $(START_DIR)/examples/main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


insertionsort.cpp.o : $(START_DIR)/insertionsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


introsort.cpp.o : $(START_DIR)/introsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


insertText.cpp.o : $(START_DIR)/insertText.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


SDLVideoDisplay.cpp.o : $(START_DIR)/SDLVideoDisplay.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raspi.cpp.o : $(START_DIR)/raspi.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


webcam.cpp.o : $(START_DIR)/webcam.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ServoBlock.cpp.o : $(START_DIR)/ServoBlock.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


categorical.cpp.o : $(START_DIR)/categorical.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


GPIOCodegen.cpp.o : $(START_DIR)/GPIOCodegen.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PWMBlock.cpp.o : $(START_DIR)/PWMBlock.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


SystemProp.cpp.o : $(START_DIR)/SystemProp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ProcessConstructorArguments.cpp.o : $(START_DIR)/ProcessConstructorArguments.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PWMBase2.cpp.o : $(START_DIR)/PWMBase2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_raspi_init.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_raspi_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_Pyserver_control.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/src/periphs/MW_Pyserver_control.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(ECHO) "### Deleted all derived files."


