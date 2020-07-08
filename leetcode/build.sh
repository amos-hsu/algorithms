#!/bin/bash
set -e
self=$(readlink -f $0)
ROOT_PATH=${self%/*}
CFLAG="-I. -g -Wall -fstack-protector-all -fPIE -std=c99 -fsanitize=address -fno-omit-frame-pointer"
LFLAG="-Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -pie -lasan"
SRC=${1}
COMPILE_CMD="gcc -c ${CFLAG} ${SRC} -o ${SRC}.o"
LINK_CMD="gcc -o MAINEXE *.o ${LFLAG}"

export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:\
					malloc_context_size=15:suppressions=$SUPP_FILE
export LD_LIBRARY_PATH=./lib

function green_echo () {
	echo -e "\033[32m${*} \033[0m\c"
}
function orange_echo () {
    echo -e "\033[34m${*}\033[0m"
}

green_echo "[  0%]" && echo "Build cleaning" && [ -f *.o ] && rm *.o && [ -f MAINEXE ] && rm MAINEXE
green_echo "[ 10%]" && echo "Scaning C sources ${SRC}"
green_echo "[ 20%]" && echo "Building C objects"
green_echo "[ 40%]" && echo "${COMPILE_CMD}" && ${COMPILE_CMD} || exit 1
green_echo "[ 60%]" && echo "Linking C excutable"
green_echo "[ 80%]" && echo "${LINK_CMD}" && ${LINK_CMD} || exit 1
green_echo "[100%]" && echo "Build success" && rm *.o
orange_echo "<RUN RESULT>"
LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libasan.so.4 ./MAINEXE
