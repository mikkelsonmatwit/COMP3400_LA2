#!/bin/sh

command="$1"

help() {
    echo   "USAGE:"
    echo   "  $0 <COMMANDS>"
    echo   ""
    echo   "  COMMANDS:"
    printf "    build\tBuild code\n"
    printf "    test\tRun tests\n"
    printf "    clean\tClear out old files\n"
    printf "    help\tPrint this help message\n"
}
build() {
    mkdir -p build
    cd build
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
    cp compile_commands.json ..
    make -j
    cd -
}
run_tests() {
    cd build
    ctest --output-on-failure
    cd -
}
clean() {
    rm -rf build
    rm -f compile_commands.json
}



if [ "$command" = "help" ]
then
    help
elif [ "$command" = "build" ]
then
    build
elif [ "$command" = "test" ]
then
    build
    run_tests
elif [ "$command" = "clean" ]
then
    rm -rf build
else
    help
fi


