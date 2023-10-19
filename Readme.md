# 3D Game Animation

> Based on "Hands-On C++ Game Animation Programming" by Gabor Szauer (2020)

## Requirements

Development is done with
* Conan 2.x
* CMake 3.27.x
* Windows: Visual Studio 2022 Community Edition
* Linux: Make

## Building

Conan install for debug and release builds
```
conan install . --build=missing --settings=build_type=Debug
conan install . --build=missing --settings=build_type=Release
```

CMake project generation

On Windows
```
cmake --preset conan-default
```

On Linux
```
cmake --preset conan-debug
cmake --preset conan-release
```

On Windows, open the generaed solution file in the build folder.
On Linux use
```
cmake --build build/Debug
cmake --build build/Release
```

## Design

```
|--------------------------------------|
|       App        |       Test        | GameAnimationApp, GameAnimationTest
|--------------------------------------|
|                 app                  | GameAnimationLib
|--------------------------------------|
|                 gfx                  |
|--------------------------------------|
|       anim       |       ik          |
|--------------------------------------|
|       util       |      math         |
|--------------------------------------|
```

## GameAnimationLib

Game animation library with renderer and skeletal animation system. Layered design.

* app - application layer
* gfx - rendering (OpenGL)
* anim - skeletal animation
* ik - inverse kinematics
* math - common math helper
* util - common utility