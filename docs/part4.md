## STL(Standard *Template* Library, 标准模板库)

提高代码的复用性

### 4.1 STL基本概念

STL从广义上分为: 容器(container), 算法(algorihm), 迭代器(iterator)

容器和算法之间通过迭代器进行无缝衔接

STL几乎所有的代码都采用了模板或者模板函数


*STL六大组件:*

容器(container), 算法(algorihm), 迭代器(iterator), 仿函数, 适配器, 空间配置器

* 1. 容器: 各种数据结构，比如vector、list、deque、set、map等，用来存放数据
* 2. 算法: 各种常用的算法， 如sort、find、copy、for_each等
* 3. 迭代器: 扮演了容器和算法之间的胶合剂
* 4. 仿函数: 行为类似函数，可作为算法的某种策略
* 5. 适配器: 用来修饰容器、仿函数、迭代器
* 6. 空间配置器: 负责空间的配置和管理

### 4.2 容器(container), 算法(algorihm), 迭代器(iterator)

常用的数据结构: 数组、链表、树、栈、队列、集合、映射表

容器分为: 
* 序列式容器: 强调值的顺序、序列式容器的每个元素均有固定的位置
* 关联式容器: 二叉树结构，各个元素之间没有严格的物理顺序

算法: 问题至解决法； 在有限的步骤中，解决逻辑或者数学上的问题

迭代器: 提供一种方式，是指能够依序寻访某个 容器中的各个元素，而又无须暴露改容器内部的表示方式

每个容器都有自己的专属迭代器；迭代器使用非常类似于指针

迭代器种类:
|       种类      |       功能       |      支持运算      |
|----------------|------------------|------------------|
|    输入迭代器    |  对数据的只读访问  |  只读，支持++、==、!= |
|    输出迭代器    |  对数据的只写访问  |  只写，支持++|
|    前向迭代器    |  读写操作，并能够向前推进迭代器  |  读写，支持++、==、!= |
|    *双向迭代器*    |  读写操作，并能够向前、向后推进迭代器  |  读写，支持++、-- |
|  随机访问迭代器   |  读写操作，可以跳跃的方式访问任意数据，功能最强的迭代器  |  只读，支持++、--、[n]、-n、 <、 <=、 >、 >= |   

## 4.3 容器算法迭代器初识

### 4.3.1 容器--vector

容器: `vector`

算法: `for_each`

迭代器: `vector<int>::iterator`, _是不是有模板那味了_

[示例](../part4/vector/example.cpp)  学习如何使用vector、存放一般的数据类型，自定义数据类型， 并且遍历其中的元素；


### 4.3.2 字符串--string

string 是C++风格的字符串，而string本质是一个类

string和char的区别:
* char* 是一个指针
* string 是一个类，类内部封装了char*，管理这个字符串，是一个char*的容器
特点:

string 内部封装了很多成员方法；例如: 查找find、拷贝copy、删除delete、替换replace、插入insert

string管理char*所分配的内存，不用担心复制越界和取值越界，由内部进行负责


*string 构造函数*:

`string();`  创建一个空的字符串 `string s1`;

`string(const char* s);`  使用字符串s初始化

`string(const string & str);`  使用一个string对象初始化另一个string对象

`string(int n, char c);`  使用n个字符从初始化

[示例](../part4/string/example.cpp)


*string 赋值操作*:

* string & operator=(const char* s);       // char* 类型字符串赋值给当前的字符串
* string & operator=(const string &s);     // 把字符串s赋给当前的字符串
* string & operator=(char c);              // 把字符赋值给当前的字符串
* string & assign(const char *s);          // 把字符串s赋值给当前的字符串
* string & assign(const char *s, int n);   // 把字符串s的前n个字符赋值给当前的字符串
* string & assign(const string &s);        // 把字符串s赋值给当前的字符串
* string & assign(int n, char c);          // 用n个字符C 赋给当前字符串


*string 拼接操作*:
* string& operator+=(const char* str);    // 重载+=运算符
* string& operator+=(const char c);       // 重载+=运算符
* string& operator+=(const string& s);    // 重载+=运算符
* string& append(const char *s);          // 把字符串s连接到当前字符串结尾
* string& append(const char *s， int n);  // 把字符串s的前n个字符连接到当前字符串结尾
* string& append(const string& s);        // 同operator+=(const char* str)
* string& append(const string& s， int pos, int n);         // 把字符串s从pos开始的第n个字符连接到当前字符串结尾


*string 查找和替换*:
int find(const string& s1, int pos=0) const;  // 查找s1第一次出现位置，从pos位置开始查找
int rfind(const string& s1, int pos=0) const; // 查找s1最后一次出现位置，从pos位置开始查找
string& replace(int pos, int n, const string & s1); //替换从pos开始的n个字符为字符串s1
