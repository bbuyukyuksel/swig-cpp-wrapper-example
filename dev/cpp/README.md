# Calling the dynamic libraries from system

To call dynamic libraries in system, we have to feed to path our `DYLD_LIBRARY_PATH` environment variable

```bash
export DYLD_LIBRARY_PATH='../library/build':$DYLD_LIBRARY_PATH
```

# Running

Before running the main.cpp code, we have to generate our library, in `dev/library` for more details check the README.md file in that directory.

```bash
./run.sh
./sample
```
