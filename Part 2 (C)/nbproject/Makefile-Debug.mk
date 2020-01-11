#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/add.o \
	${OBJECTDIR}/boolean.o \
	${OBJECTDIR}/charStar.o \
	${OBJECTDIR}/conversions.o \
	${OBJECTDIR}/create.o \
	${OBJECTDIR}/dijkstra.o \
	${OBJECTDIR}/display.o \
	${OBJECTDIR}/findAndAdd.o \
	${OBJECTDIR}/free.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menus.o \
	${OBJECTDIR}/structAlgorithm.o \
	${OBJECTDIR}/structGetters.o \
	${OBJECTDIR}/structVilleGetters.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_td7_8.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_td7_8.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_td7_8 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/add.o: add.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/add.o add.c

${OBJECTDIR}/boolean.o: boolean.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/boolean.o boolean.c

${OBJECTDIR}/charStar.o: charStar.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/charStar.o charStar.c

${OBJECTDIR}/conversions.o: conversions.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/conversions.o conversions.c

${OBJECTDIR}/create.o: create.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/create.o create.c

${OBJECTDIR}/dijkstra.o: dijkstra.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dijkstra.o dijkstra.c

${OBJECTDIR}/display.o: display.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/display.o display.c

${OBJECTDIR}/findAndAdd.o: findAndAdd.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/findAndAdd.o findAndAdd.c

${OBJECTDIR}/free.o: free.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/free.o free.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/menus.o: menus.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menus.o menus.c

${OBJECTDIR}/structAlgorithm.o: structAlgorithm.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/structAlgorithm.o structAlgorithm.c

${OBJECTDIR}/structGetters.o: structGetters.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/structGetters.o structGetters.c

${OBJECTDIR}/structVilleGetters.o: structVilleGetters.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -include my.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/structVilleGetters.o structVilleGetters.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
