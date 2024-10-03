# dylib-hotreload-c

Sample hello world for loading a dynamic library in C++ for MacOS.

An example use case is in game engines that allow attaching scripts writen in C++ which need to be compiled on the fly as they are changed in the game engine UI and then we want to see the outcome while running the game in the engine without having to go through an engine recompilation or restart of any kind. We would want to generate a library from the C++ source files and load them dynamically in the engine on a per-need basis.

Other examples relevant to the real world include any application that might need to have parts of itself updated without an application reboot, and without running separate processes that communicate with each other via requests rather than being the same process.

## build

```
./dynamic.sh
```

```
g++ -dynamiclib -o libdynamic.dylib dynamic.cpp
```
