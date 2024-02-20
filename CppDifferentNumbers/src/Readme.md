# Standalone C++ example for C++

Here we describe how to build and run the C++ example file. 

Running the Example
===================

1. Create a new subdirectory within the CppKeyDerivation/src directory such as 
   CppDifferentNumbers/src/myexample  (or any other name). 

2. Navigate to the new subdirectory you created.
   All subsequent commands have to be executed in this subdirectory.

3. Execute instructions from one of the following subsections, depending on the build system or target you are using.

4. Run the application and observe the console output.

5. Set "SKB_ROOT" variable - it should point to the directory where SKB release is unzipped. 
   Directory $SKB_ROOT should contain subdirectories "lib" and "Include". 



## VS 2022 on Windows 10 or Windows 11

```
cmake -B build -G "Visual Studio 17 2022"
cmake --build build --config Release

```


## Xcode on Mac OS X

```
cd myexample
cmake -G "Xcode" .. -DCMAKE_OSX_DEPLOYMENT_TARGET=11 -DSKB_TARGET_LIB_DIR="$SKB_ROOT/lib/apple/macosx"
cmake --build . --config Release
./Release/MySample.app/Contents/MacOS/MySample
```