cmake_minimum_required(VERSION 3.5)
project(demo)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(hello hello.cpp)

# 链接库
# target_link_libraries(my_program some_library)
