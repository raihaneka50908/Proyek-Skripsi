###########################################################################
## Makefile generated for component 'memahami_push_button'. 
## 
## Makefile     : memahami_push_button_rtw.mk
## Generated on : Wed Jun 22 11:26:45 2022
## Final product: $(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/memahami_push_button.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = memahami_push_button
MAKEFILE                  = memahami_push_button_rtw.mk
MATLAB_ROOT               = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2020b
MATLAB_BIN                = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = $(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/codegen/exe/memahami_push_button
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

PRODUCT = $(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/memahami_push_button.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server -I$(START_DIR)/examples -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/include -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMW_PWMBLOCK -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_MATLABTARGET
DEFINES_CUSTOM = 
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=200000
DEFINES_STANDARD = -DMODEL=memahami_push_button

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_video_display.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/devices.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/GPIO.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_pigs.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/system.c $(START_DIR)/memahami_push_button_main_terminate.cpp $(START_DIR)/memahami_push_button_data.cpp $(START_DIR)/memahami_push_button_initialize.cpp $(START_DIR)/memahami_push_button_terminate.cpp $(START_DIR)/memahami_push_button.cpp $(START_DIR)/examples/main.cpp $(START_DIR)/SDLVideoDisplay.cpp $(START_DIR)/raspi.cpp $(START_DIR)/GPIOCodegen.cpp $(START_DIR)/PWMBlock.cpp $(START_DIR)/PWMBase2.cpp $(START_DIR)/memahami_push_button_rtwutil.cpp $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_raspi_init.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/src/periphs/MW_Pyserver_control.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_video_display.c.o devices.c.o GPIO.c.o MW_pigs.c.o system.c.o memahami_push_button_main_terminate.cpp.o memahami_push_button_data.cpp.o memahami_push_button_initialize.cpp.o memahami_push_button_terminate.cpp.o memahami_push_button.cpp.o main.cpp.o SDLVideoDisplay.cpp.o raspi.cpp.o GPIOCodegen.cpp.o PWMBlock.cpp.o PWMBase2.cpp.o memahami_push_button_rtwutil.cpp.o MW_raspi_init.c.o MW_Pyserver_control.c.o

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -lpigpio
CPP_LDFLAGS_SKIPFORSIL = -lSDL

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -lpigpio
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -lSDL

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_ = -lpigpio
LDFLAGS_SKIPFORSIL = -lSDL

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -lpigpio
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


%.c.o : $(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_WORKSPACE)/E/For_Learning/My_Future_Skripsi/Program_Raspberry_Pi/Classification_Program/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/examples/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/examples/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/examples/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_video_display.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_video_display.c
	$(CC) $(CFLAGS) -o "$@" "$<"


devices.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/devices.c
	$(CC) $(CFLAGS) -o "$@" "$<"


GPIO.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/GPIO.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_pigs.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/MW_pigs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/realtime/targets/raspi/server/system.c
	$(CC) $(CFLAGS) -o "$@" "$<"


memahami_push_button_main_terminate.cpp.o : $(START_DIR)/memahami_push_button_main_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


memahami_push_button_data.cpp.o : $(START_DIR)/memahami_push_button_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


memahami_push_button_initialize.cpp.o : $(START_DIR)/memahami_push_button_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


memahami_push_button_terminate.cpp.o : $(START_DIR)/memahami_push_button_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


memahami_push_button.cpp.o : $(START_DIR)/memahami_push_button.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


main.cpp.o : $(START_DIR)/examples/main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


SDLVideoDisplay.cpp.o : $(START_DIR)/SDLVideoDisplay.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raspi.cpp.o : $(START_DIR)/raspi.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


GPIOCodegen.cpp.o : $(START_DIR)/GPIOCodegen.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PWMBlock.cpp.o : $(START_DIR)/PWMBlock.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PWMBase2.cpp.o : $(START_DIR)/PWMBase2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


memahami_push_button_rtwutil.cpp.o : $(START_DIR)/memahami_push_button_rtwutil.cpp
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


