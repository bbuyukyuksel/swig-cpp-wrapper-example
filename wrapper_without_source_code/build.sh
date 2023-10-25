#!/bin/bash

./copy.sh

PYTHON_INCLUDE_DIR=/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/include/python3.8
PYTHON_LIBRARY_DIR=/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/lib

SOURCE_DYNAMIC_LIBRARY_PATH="./"
SOURCE_DYNAMIC_LIBRARY_NAME="mylib"
DYNAMIC_WRAPPER_OUTNAME="myclass"

export DYLD_LIBRARY_PATH="$PYTHON_LIBRARY_DIR":$DYLD_LIBRARY_PATH
export DYLD_LIBRARY_PATH="$SOURCE_DYNAMIC_LIBRARY_PATH":$DYLD_LIBRARY_PATH

swig -c++ -python "${SOURCE_DYNAMIC_LIBRARY_NAME}.i"
g++ -std=c++17 -O2 -fPIC -c "${SOURCE_DYNAMIC_LIBRARY_NAME}_wrap.cxx" -I$PYTHON_INCLUDE_DIR
g++ -std=c++17 -L$PYTHON_LIBRARY_DIR  -L$SOURCE_DYNAMIC_LIBRARY_PATH -l$SOURCE_DYNAMIC_LIBRARY_NAME -lpython3.8 -dynamiclib "${SOURCE_DYNAMIC_LIBRARY_NAME}_wrap.o" -o "_${DYNAMIC_WRAPPER_OUTNAME}.so"

rm *cxx *.o 