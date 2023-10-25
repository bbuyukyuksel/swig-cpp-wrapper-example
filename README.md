# Explaining

`dev/` folder is the part related to the development and testing of the C++ library.

`wrapper_with_source/` code is the section where a code with C++ source codes is wrapped with Python.

`wrapper_without_source/` code is the section where a dynamic library that does not have C++ codes is wrapped with Python.

# While starting,

1. First, the dynamic library needs to be created. To do this, the `./build.sh` script in the `dev/library` directory must be run.

```bash
# to run build script,
chmod +x build.sh
./build.sh
```

2. The next step is to perform the wrapper operation. For this, the `build.sh` script in `wrapper_without_source_code` should be run and the path of the dynamic library should be specified in the `LD_LIBRARY_PATH` variable. For more details, you can check out the README file in the directory.

3. To test Wrapper on the Python side, the `main.py` script has been prepared in the relevant directory for this process.