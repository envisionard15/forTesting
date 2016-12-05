# forTesting

Please downlaod the pretrain model (https://docs.google.com/uc?export=download&id=0B2UgaM91sqeAN0dJb05jWThJUUk) into the project root folder.

To build with windows caffe, the installtion path is set to default.

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
