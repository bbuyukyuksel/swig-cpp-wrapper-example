# Requirements

- brew install swig
- brew install python@3.8

# Python Include:

```python
import sysconfig
print(sysconfig.get_path('include'))
```

## MacOS
/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/include/python3.8

## Linux
?


# Dynamic Lib

/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/lib

libpython3.8.dylib


# Compiling

```bash
PYTHON_INCLUDE_DIR=/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/include/python3.8
PYTHON_LIBRARY_DIR=/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/lib

export DYLD_LIBRARY_PATH="$PYTHON_LIBRARY_DIR":$DYLD_LIBRARY_PATH

swig -c++ -python MyClass.i
g++ -O2 -fPIC -c MyClass.cpp
g++ -O2 -fPIC -c  MyClass_wrap.cxx -I$PYTHON_INCLUDE_DIR
g++ -L$PYTHON_LIBRARY_DIR  -lpython3.8 -dynamiclib MyClass.o MyClass_wrap.o -o _myclass.so
```

# clean
rm -rf *o *cxx __pycache__ *py  

# old notes

swig -c++ -python MyClass.i
g++ -O2 -fPIC -c MyClass.cpp
g++ -O2 -fPIC -c  MyClass_wrap.cxx -I/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/include/python3.8
g++ -L/opt/homebrew/Cellar/python@3.8/3.8.18/Frameworks/Python.framework/Versions/3.8/lib  -lpython3.8 -dynamiclib MyClass.o MyClass_wrap.o -o _myclass.so

```python
>>> import myclass
>>> cls = myclass.MyClass()
>>> cls.add(3, 4)
7
```