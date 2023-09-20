# 最低的cmake版本
cmake_minimum_required(VERSION 3.5)

# 声明了项目的名称(recipe-01)和支持的编程语言(CXX代表C++):
project(recipe3 LANGUAGES CXX)

# generate a library from sources, 创建目标——STATIC静态库, 库的名称和源码文件名相同
# 第一个参数是目标名, 
# 第二个参数
#    STATIC：创建一个静态库，默认为静态库。静态库是在编译时与可执行文件静态链接的库，生成的库文件名通常以 .a 或 .lib 结尾。
#    SHARED：创建一个共享库。共享库是在运行时动态加载并链接的库，生成的库文件名通常以 .so 或 .dll 结尾。
#    MODULE：创建一个模块库。模块库类似于共享库，但在一些系统上具有特定的用途。生成的库文件名通常以 .so 或 .dll 结尾。
#    EXCLUDE_FROM_ALL：将目标从构建过程中排除，即不会被默认构建。使用此选项可以将目标作为可选构建目标。
# 第三个参数是 *.cpp 列表
add_library(message
  STATIC
    Message.hpp
    Message.cpp
  )

# 指示CMake创建一个新目标: 可执行文件main
add_executable(main main.cpp)

# 将目标库链接到可执行目标文件
target_link_libraries(main message)