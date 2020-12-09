##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MCDandMCM
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Fabio/Documents/PrimiProgrammi
ProjectPath            :=C:/Users/Fabio/Documents/PrimiProgrammi/MCM
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Fabio
Date                   :=06/02/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="MCDandMCM.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/MCD.c$(ObjectSuffix) $(IntermediateDirectory)/ControlloNumeri.c$(ObjectSuffix) $(IntermediateDirectory)/MCM.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Fabio/Documents/PrimiProgrammi/MCM/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/MCD.c$(ObjectSuffix): MCD.c $(IntermediateDirectory)/MCD.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Fabio/Documents/PrimiProgrammi/MCM/MCD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MCD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MCD.c$(DependSuffix): MCD.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MCD.c$(ObjectSuffix) -MF$(IntermediateDirectory)/MCD.c$(DependSuffix) -MM MCD.c

$(IntermediateDirectory)/MCD.c$(PreprocessSuffix): MCD.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MCD.c$(PreprocessSuffix) MCD.c

$(IntermediateDirectory)/ControlloNumeri.c$(ObjectSuffix): ControlloNumeri.c $(IntermediateDirectory)/ControlloNumeri.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Fabio/Documents/PrimiProgrammi/MCM/ControlloNumeri.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ControlloNumeri.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ControlloNumeri.c$(DependSuffix): ControlloNumeri.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ControlloNumeri.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ControlloNumeri.c$(DependSuffix) -MM ControlloNumeri.c

$(IntermediateDirectory)/ControlloNumeri.c$(PreprocessSuffix): ControlloNumeri.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ControlloNumeri.c$(PreprocessSuffix) ControlloNumeri.c

$(IntermediateDirectory)/MCM.c$(ObjectSuffix): MCM.c $(IntermediateDirectory)/MCM.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Fabio/Documents/PrimiProgrammi/MCM/MCM.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MCM.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MCM.c$(DependSuffix): MCM.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MCM.c$(ObjectSuffix) -MF$(IntermediateDirectory)/MCM.c$(DependSuffix) -MM MCM.c

$(IntermediateDirectory)/MCM.c$(PreprocessSuffix): MCM.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MCM.c$(PreprocessSuffix) MCM.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


