##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Matrici
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/noxium/Documents/C/C
ProjectPath            :=/home/noxium/Documents/C/C/Matrici
IntermediateDirectory  :=../build-$(ConfigurationName)/Matrici
OutDir                 :=../build-$(ConfigurationName)/Matrici
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Noxium
Date                   :=04/07/21
CodeLitePath           :=/home/noxium/.codelite
LinkerName             :=/usr/bin/g++-8
SharedObjectLinkerName :=/usr/bin/g++-8 -shared -fPIC
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
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-8
CC       := /usr/bin/gcc-8
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Matrici/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Matrici/Complex.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Matrici/Matrice.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Matrici/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Matrici"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Matrici"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Matrici/.d:
	@mkdir -p "../build-$(ConfigurationName)/Matrici"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(ObjectSuffix): Matrice_patratica.cpp ../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/Matrici/Matrice_patratica.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Matrice_patratica.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(DependSuffix): Matrice_patratica.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(DependSuffix) -MM Matrice_patratica.cpp

../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(PreprocessSuffix): Matrice_patratica.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Matrici/Matrice_patratica.cpp$(PreprocessSuffix) Matrice_patratica.cpp

../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(ObjectSuffix): Matrice_oarecare.cpp ../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/Matrici/Matrice_oarecare.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Matrice_oarecare.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(DependSuffix): Matrice_oarecare.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(DependSuffix) -MM Matrice_oarecare.cpp

../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(PreprocessSuffix): Matrice_oarecare.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Matrici/Matrice_oarecare.cpp$(PreprocessSuffix) Matrice_oarecare.cpp

../build-$(ConfigurationName)/Matrici/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Matrici/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/Matrici/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Matrici/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Matrici/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Matrici/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Matrici/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Matrici/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Matrici/Complex.cpp$(ObjectSuffix): Complex.cpp ../build-$(ConfigurationName)/Matrici/Complex.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/Matrici/Complex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Complex.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Matrici/Complex.cpp$(DependSuffix): Complex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Matrici/Complex.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Matrici/Complex.cpp$(DependSuffix) -MM Complex.cpp

../build-$(ConfigurationName)/Matrici/Complex.cpp$(PreprocessSuffix): Complex.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Matrici/Complex.cpp$(PreprocessSuffix) Complex.cpp

../build-$(ConfigurationName)/Matrici/Matrice.cpp$(ObjectSuffix): Matrice.cpp ../build-$(ConfigurationName)/Matrici/Matrice.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/noxium/Documents/C/C/Matrici/Matrice.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Matrice.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Matrici/Matrice.cpp$(DependSuffix): Matrice.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Matrici/Matrice.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Matrici/Matrice.cpp$(DependSuffix) -MM Matrice.cpp

../build-$(ConfigurationName)/Matrici/Matrice.cpp$(PreprocessSuffix): Matrice.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Matrici/Matrice.cpp$(PreprocessSuffix) Matrice.cpp


-include ../build-$(ConfigurationName)/Matrici//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


