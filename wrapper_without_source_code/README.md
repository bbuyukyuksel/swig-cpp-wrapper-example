

# Compiling

Set the dynamic library path

```bash
export DYLD_LIBRARY_PATH="./":$DYLD_LIBRARY_PATH
```

Build the wrapper to use in python programming language
```bash
./build.sh
```

# Usage
```python
import myclass

if __name__ == '__main__':
    cls = myclass.MyClass()

    date01 = myclass.Date(2023, 10, 5)
    print(cls.printDate(date01))

    date02 = myclass.Date(2020, 5, 10)
    print(cls.printDate(date02))

    
```

# Old Build Style

```bash
PYTHON_INCLUDE_DIR=/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/include/python3.8
PYTHON_LIBRARY_DIR=/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/lib

SOURCE_DYNAMIC_LIBRARY_PATH="./"
SOURCE_DYNAMIC_LIBRARY_NAME="mylib"
DYNAMIC_WRAPPER_OUTNAME="myclass"

export DYLD_LIBRARY_PATH="$PYTHON_LIBRARY_DIR":$DYLD_LIBRARY_PATH
export DYLD_LIBRARY_PATH="$SOURCE_DYNAMIC_LIBRARY_PATH":$DYLD_LIBRARY_PATH

swig -c++ -python "${SOURCE_DYNAMIC_LIBRARY_NAME}.i"
g++ -O2 -fPIC -c "${SOURCE_DYNAMIC_LIBRARY_NAME}_wrap.cxx" -I$PYTHON_INCLUDE_DIR
g++ -L$PYTHON_LIBRARY_DIR  -L$SOURCE_DYNAMIC_LIBRARY_PATH -l$SOURCE_DYNAMIC_LIBRARY_NAME -lpython3.8 -dynamiclib "${SOURCE_DYNAMIC_LIBRARY_NAME}_wrap.o" -o "_${DYNAMIC_WRAPPER_OUTNAME}.so"
```

# clean
rm -rf *o *cxx __pycache__ *py  