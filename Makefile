PROGRAM_NAME = type-speed

COMPILER = gcc

CXX_COMPILE_FLAGS = std=c++11 -Ofast
CXX_LINK_FLAGS = -lstdc++ -lncurses

OBJECT_FILES_DIR = objs
OBJECT_FILES = main.o \
               game_engine.o

SOURCE_FILES_DIR = type-speed/src
HEADER_FILES_DIR = type-speed/include

prepare:
    @printf "%s\n" "creating directory for object files..."
    @if [ ! -d "${OBJECT_FILES_DIR}" ] ; then mkdir -v "${OBJECT_FILES_DIR}" ; fi

${PROGRAM_NAME}: ${OBJECT_FILES}
    ${COMPILER} ${OBJECT_FILES} ${CXX_LINK_FLAGS} -o ${PROGRAM_NAME}

main.o: ${SOURCE_FILES_DIR}/main.cpp
    @printf "%s\n" "> compiling main.cpp file"
    ${COMPILER} ${SOURCE_FILES_DIR}/main.cpp ${CXX_COMPILE_FLAGS} -o ${OBJECT_FILES_DIR}/main.o

game_engine: ${SOURCE_FILES_DIR}/game_engine.cpp
    @printf "%s\n" "> compiling game_engine.cpp file"
    ${COMPILER} ${SOURCE_FILES_DIR}/game_engine.cpp ${CXX_COMPILE_FLAGS} -o ${OBJECT_FILES_DIR}/game_engine.o

clean:
    @printf "%s\n" "removing files..."
    @rm -rvf ${OBJECT_FILES_DIR} ${PROGRAM_NAME}
