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

## Libraries
`RadioLib` repo
```
https://github.com/jgromes/RadioLib
```
Currently gives an error of `-5` related to TX recognition. To do with the `GDO0` pin.

`SpaceTeddy` repo 
```
https://github.com/SpaceTeddy/CC1101
```
No issues and works as expected.
