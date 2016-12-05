# forTesting

Please downlaod the pretrain model (https://docs.google.com/uc?export=download&id=0B2UgaM91sqeAN0dJb05jWThJUUk) into the project root folder.

clone caffe
```
git clone https://github.com/BVLC/caffe.git windows-caffe
cd windows-caffe
git checkout windows
```

To build with windows caffe, the installtion path is set to default.

Here are the other options when building caffe

```
    :: Change the settings here to match your setup
    :: Change MSVC_VERSION to 12 to use VS 2013
    if NOT DEFINED MSVC_VERSION set MSVC_VERSION=12
    :: Change to 1 to use Ninja generator (builds much faster)
    if NOT DEFINED WITH_NINJA set WITH_NINJA=1
    :: Change to 1 to build caffe without CUDA support
    if NOT DEFINED CPU_ONLY set CPU_ONLY=0
    :: Change to Debug to build Debug. This is only relevant for the Ninja generator the Visual Studio generator will generate both Debug and Release configs
    if NOT DEFINED CMAKE_CONFIG set CMAKE_CONFIG=Release
    :: Change to 1 to build a caffe.dll
    if NOT DEFINED CMAKE_BUILD_SHARED_LIBS set CMAKE_BUILD_SHARED_LIBS=0
    :: Change these options for your needs.
    if NOT DEFINED BUILD_PYTHON set BUILD_PYTHON=0
    if NOT DEFINED BUILD_PYTHON_LAYER set BUILD_PYTHON_LAYER=0
    if NOT DEFINED BUILD_MATLAB set BUILD_MATLAB=0
    :: If python is on your path leave this alone
    if NOT DEFINED PYTHON_EXE set PYTHON_EXE=python
    :: Run the tests
    if NOT DEFINED RUN_TESTS set RUN_TESTS=0
    :: Run lint
    if NOT DEFINED RUN_LINT set RUN_LINT=0
    :: Build the install target
    if NOT DEFINED RUN_INSTALL set RUN_INSTALL=1

```

And ensure the windows-caffe is built to the static library and the root folder of windows-caffe is located in the same folder of this project. (See the CMakeList.txt for the detail)



### Build
```
mkdir build
cd build
cmake -G"Visual Studio 12 2013 Win64" ..
cmake --build . --config Release
```
### Issue
```
# will throw the exception MemoryDataLayer not found
Release/NativeTrainer.exe 
```
