# 最低的cmake版本
cmake_minimum_required(VERSION 3.5)

# 声明了项目的名称(recipe-01)和支持的编程语言(CXX代表C++):
project(demo LANGUAGES CXX)

# 指示CMake创建一个新目标：可执行文件hello-world
add_executable(main main.cpp)
