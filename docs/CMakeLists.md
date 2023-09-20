## 学习CMakeLists

CMake是一个构建系统生成器，可以使用单个CMakeLists.txt为不同平台上的不同工具集配置项目


### 1. [初识demo](../part5_CMakeLists/demo/)

一个源文件和*CMakeLists.txt*放在同一个目录, *run.sh*脚本内容如下：

```run.sh
cd $(demo)
mkdir build
cd build
cmake ..
make
./main 
```

默认情况下，在GNU/Linux和macOS系统上，CMake使用Unix Makefile生成器。Windows上，Visual Studio是默认的生成器。运行完`./run.sh`之后，生成为文件：

* Makefile: make将运行指令来构建项目。
* CMakefile：包含临时文件的目录，CMake用于检测操作系统、编译器等。此外，根据所选的生成器，它还包含特定的文件。
* cmake_install.cmake：处理安装规则的CMake脚本，在项目安装时使用。
* CMakeCache.txt：如文件名所示，CMake缓存。CMake在重新运行配置时使用这个文件。

*Ref:* 
[教程1](https://zhuanlan.zhihu.com/p/534439206)
[中文文档](https://www.bookstack.cn/read/CMake-Cookbook/README.md)