# import ctypes

# # Kütüphane yükleyin
# mylib = ctypes.CDLL('./libmylib.dylib')

# # Fonksiyonları çağırın
# result = mylib.add(5, 3)
# print("5 + 3 =", result)

# array = (ctypes.c_int * 5)(1, 2, 3, 4, 5)
# total = mylib.add_all(array, len(array))
# print("Sum of array:", total)

from ctypes.util import find_library
import ctypes
import os

os.environ["DYLD_LIBRARY_PATH"] = os.pathsep.join((os.environ.get("DYLD_LIBRARY_PATH", ""), os.path.join(os.getcwd(), "libs")))

cwd = os.getcwd()
lib = f'{cwd}/libs/libmylibc.dylib'

if find_library(lib):
    mylib = ctypes.cdll.LoadLibrary(lib)
else:
    raise OSError("Could not find lib.")

# Fonksiyonları çağırın
result = mylib.add(5, 3)
print("5 + 3 =", result)

array = (ctypes.c_int * 5)(1, 2, 3, 4, 5)
total = mylib.add_all(array, len(array))
print("Sum of array:", total)