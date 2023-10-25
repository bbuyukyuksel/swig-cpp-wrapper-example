## without extern "C" building

```shell
objdump -t libs/libmylib.dylib 
```

```text
libs/libmylib.dylib:    file format mach-o arm64

SYMBOL TABLE:
0000000000003f28 g     F __TEXT,__text __Z3addii
0000000000003f48 g     F __TEXT,__text __Z7add_allPii
```

```python
$ python3 wrapper.py

Traceback (most recent call last):
  File "/Users/bbuyukyuksel/Documents/Works/Cpp-Python-Wrapper/dev/python/wrapper.py", line 29, in <module>
    result = mylib.add(5, 3)
  File "/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Versions/3.9/lib/python3.9/ctypes/__init__.py", line 379, in __getattr__
    func = self.__getitem__(name)
  File "/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Versions/3.9/lib/python3.9/ctypes/__init__.py", line 384, in __getitem__
    func = self._FuncPtr((name_or_ordinal, self))
AttributeError: dlsym(0xa6acb690, add): symbol not found
```

## with extern "C" building

```shell
objdump -t libs/libmylibc.dylib 
```

```text
libs/libmylibc.dylib:   file format mach-o arm64

SYMBOL TABLE:
0000000000003f28 g     F __TEXT,__text _add
0000000000003f48 g     F __TEXT,__text _add_all
```

```python
$ python3 wrapper.py

5 + 3 = 8
Sum of array: 15
```
