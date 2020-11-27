#!/bin/bash

set -e
self=$(readlink -f $0)
ROOT_PARH=${self%/*}
ASAN_ENABLE="y"    # default enable asan

function usage() {
    echo "Usage:"
    echo "    ./build.sh [-f source_file_path] [-s y/n]"
    echo "    -f [source_file_path]       source file absolute path"
    echo "    -s [y/n]                    enable asan"
    exit 1
}

function green_echo () {
    echo -e "\033[32m${*} \033[0m\c"
}

function orange_echo () {
    echo -e "\033[34m${*}\033[0m"
}

if [ $# == 0 ]; then
    echo "param null" && usage
fi
while getopts ":hf:s:" arg; do
    case $arg in
        f) # source file
            if [ -n ${OPTARG}  ]; then
                SRC_DIR=$(dirname "${OPTARG}")
                SRC_FILE_NAME=${OPTARG##*/}
            else
                echo "param error: ${OPTARG}" && usage && exit 1
            fi ;;
        s) # enable asan (address sanitize)
            if [ ${OPTARG} == "y" -o ${OPTARG} == "n" ]; then
                ASAN_ENABLE=${OPTARG}
            else
                echo "param error: ${OPTARG}" && usage && exit 1
            fi ;;
        h)  usage;;
        ?)  echo "unkonw option" && usage;;
    esac
done

CFLAG="-I. -I /usr/include -g -Wall -fstack-protector-all -fPIE -std=c99 "
LDFLAG="-Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -pie -ldl -lpthread "
if [ ${ASAN_ENABLE} == "y" ]; then
    CFLAG+="-fsanitize=address -fno-omit-frame-pointer -fno-omit-frame-pointer"
    LDFLAG+="-lasan "
fi

LIB_ASAN_DIR=$(find /usr -name "libasan.so.4")  # or get by: `find / -name "libasan.so.4"`
COMPILE_CMD="gcc -c ${CFLAG} ${SRC_DIR}/${SRC_FILE_NAME} -o ${ROOT_PARH}/${SRC_FILE_NAME}.o"
LINK_CMD="gcc -o main ${SRC_FILE_NAME}.o ${LDFLAG}"

green_echo "[  0%]" && echo "Build clean" && [ -f ${SRC_FILE_NAME}.o ] && rm ${SRC_FILE_NAME}.o && [ -f main ] && rm main
green_echo "[ 10%]" && echo "Scan C sources ${SRC_DIR}/${SRC_FILE_NAME}"
green_echo "[ 20%]" && echo "gcc -c ${SRC_FILE_NAME} -o ${SRC_FILE_NAME}.o" && ${COMPILE_CMD} || exit 1
green_echo "[ 60%]" && echo "Linking C executale"
green_echo "[ 80%]" && echo "${LINK_CMD}" && ${LINK_CMD} && rm ${SRC_FILE_NAME}.o || exit 1
green_echo "[100%]" && echo "Build success"

orange_echo "< RUN RESULT >"
export LD_LIBRARY_PATH=./lib
export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:suppressions=$SUPP_FILE

if [ ${ASAN_ENABLE} == "y" ]; then  # default enable asan
    LD_PRELOAD=${LIB_ASAN_DIR} ./main
else
    ./main
fi
