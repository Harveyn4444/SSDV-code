# Radio Code Examples


## CMake
```
Project_Folder/
                main.cpp
                CMakeLists.txt
```
Then create a `build` directory:

```
mkdir bulid && cd build
```

Then once inside `Project_Folder/build`

```
cmake ..

make -j4
```

To then run the code
```
./"PROJECT_NAME"
```
`"PROJECT_NAME"` is declared in the `CMakeLists.txt`
