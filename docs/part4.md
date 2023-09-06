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


*[vector基本概念](../part4/vector/main.cpp)*

功能:vector数据结构和数组非常相似，也称为单端数组

vector与普通数组的区别: vector -- 动态扩展，不是在原来的空间继续接新空间，而是寻找更大的空间，然后将元数据拷贝到新空间，释放原空间； 数组是静
态空间

*1. vector构造函数*

`vector<T> v;`  采用模板实现类实现，默认构造函数
 
`vector(v.begin(), v.end());`  将v.begin(), v.end()区间的元素拷贝给本身

`vector(n, elem);` 构造函数将n个elem拷贝给本身

`vector(const vector &vec);` 拷贝构造函数

*2. vector 赋值*

`vector& operator=(const vector &vec)`

`assign(begin, end);`

`assign(n, elem);`

*3. vector 容量和大小*

`empty();` // 判断容器是否为空，空返回true, 不为空返回false

`capacity();`  // 容器的容量，返回整型数值

`size();`  // 返回容器元素的个数
 
`resize(int num);`  // 重新指定容器的长度为num, 若容器边长，则以默认值填充新的位置，如果容器变短，则末尾超出容器长度的元素会被删除掉

`reize(int num, elem);`  // 重新指定容器的长度为num, 若容器边长，则以元素值elem填充新的位置，如果容器变短，则末尾超出容器长度的元素会被删除掉

*4. vector 插入和删除*

`v1.push_back(elem);` // 使用push_back在容器末尾添加元素elem

`v1.pop_back();`  // 使用pop_back在容器末尾删除一个元素

`v1.insert(v1.begin(), 100);`  // 迭代器指向位置插入元素elem

`v1.insert(v1.begin(), 2, 100);`  // 迭代器指向位置pos插入count个元素elem

`v1.erase(v1.begin());`  // 删除迭代器指向的元素

`v1.erase(v1.begin(), v1.end());`  // 删除迭代器从begin到end之间的元素

`v1.clear();` // 删除容器中的所有元素


*5. vector 访问元素*
```
for (int i=0; i<v1.size(); i++){
    cout << v1[i] << " ";  // 通过[]访问
}
cout << endl;

for (int i=0; i<v1.size(); i++){
    cout << v1.at(i) << " ";  // 通过at访问
}
cout << endl;

cout << "First elem of v1, v1.front(): " << v1.front() << endl; // 第一个元素
cout << "Last elem of v1, v1.front(): " << v1.back() << endl;  // 最后一个元素
```

*6. vector 互换容器*

v1.swap(v2); 将容器v1和v2互换

利用swap收缩空间

*7. vector 预留空间*

vector动态空间扩展



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


*string 比较大小*:
`s1.compare(s2)` 类似python


*string 访问和修改其中的字符*:

通过[]访问字符串中的字符

通过string.at()访问字符串中的字符

修改字符串中的字符

*string 插入和删除*:

// insert
`string& insert(int pos, const char * s);`， 插入字符串

`string& insert(int pos, const string & str);`， 插入字符串

`string& insert(int pos, int n, char c);`， 在指定位置插入n个字符c

`s1.insert(1, "111");`  //在第一个位置插入 111

// erase
`string& erase(int pos, int n);`, 
`s1.erase(1, 3);`  //从第一个位置开始删除三个字符


### 4.3.3 [deque](../part4/deque/main.cpp)

功能: 双端数组，可以对头端进行插入和删除

deque 与 vector的区别:
* vector对于头部的插入和删除效率较低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度会比vector快
* vector访问元素时的速度比deque快，这和两者的背部实现相关

*1. 构造函数* 

`deque<T> deq;`  采用模板实现类实现，默认构造函数
 
`deque(deque.begin(), deque.end());`  将deque.begin(), deque.end()区间的元素拷贝给本身

`deque(n, elem);` 构造函数将n个elem拷贝给本身

`deque(const deque &deq);` 拷贝构造函数

push_back
pop_back
push_front
pop_front


*2. deque 赋值*

`deque& operator=(const deque &deq)`

`assign(begin, end);`

`assign(n, elem);`


*3. deque 大小*

`empty();` // 判断容器是否为空，空返回true, 不为空返回false

<!-- `capacity();`  // 容器的容量，返回整型数值 -->  deque没有capacity()方法, 无限空间

`size();`  // 返回容器元素的个数
 
`resize(int num);`  // 重新指定容器的长度为num, 若容器边长，则以默认值填充新的位置，如果容器变短，则末尾超出容器长度的元素会被删除掉

`reize(int num, elem);`  // 重新指定容器的长度为num, 若容器边长，则以元素值elem填充新的位置，如果容器变短，则末尾超出容器长度的元素会被删除掉


*4. deque 插入和删除*


*5. deque 访问*

和vector相似， 可以通过`[]` `at` 访问


[评委打分](../part4/deque/score.cpp)


### 4.3.4 [栈--stack](../part4/stack/main.cpp)

*先进后出*(first in last out, FILO)的数据结构，只有一个出口*栈顶*

栈中只有顶端的元素才可以被外界使用，因此*栈不允许有遍历行为*

*1. 构造函数*

*2. 赋值*
进入 push()
出来 pop()

*3. 数据存取*

*4. 大小操作*
具有 `empty()` `size()` 方法


### 4.3.4 [队列--queue](../part4/queue/main.cpp)

*先进先出*(first in first out, FIFO)的数据结构，只有*队头*和*队尾*

队列中只有两端的元素才可以被外界使用，因此*队列不允许有遍历行为*

*1. 构造函数*
queue<T> que;

queue(const queue &que);

*2. 赋值*
queue & operator=(const queue & que)

*3. 数据存取*

push(elem);

pop();

back();

front(); 

*4. 大小操作*
具有 `empty()` `size()` 方法


### 4.3.5 [链表--list](../part4/list/main.cpp)

*数据域 + 指针域* *双向循环链表*

链表的存储方式不是连续的内存空间，因此链表中的迭代器只支持前移和后移，属于双向迭代器

优点: 
* 1. 可以对任意位置进行快速删除和插入操作
* 2. 采用动态存储分配，不会造成内存浪费和溢出

缺点: 对于元素的遍历速度，没有数组快； 占用的空间比数组大


*1. 构造函数*
`list<T> lst;`            // 类模板实现， 对象的默认构造形式
`list(begin, end);`       // 将区间元素拷贝给本身
`list(n, elem);`          // 将n个elem拷贝给本身
`list(const list &lst);`  // 拷贝构造函数


*2. 赋值assign*
assin(begin(), end());

assin(n, elem);

list& operator=(const list &lst);

*3. 交换swap*
swap(lst);

*4. 大小操作*
`empty();`    // 空为true，非空为false

`size();`     // 大小判断

`resize(n);`  // 重新指定容器的长度为num, 若容器边长，则以元素值elem填充新的位置，如果容器变短，则末尾超出容器长度的元素会被删除掉

*5. 插入和删除*

push_back

push_front

pop_back

pop_front

insert

erase

clear

remove

*6. 数据存取*

由于list不是由连续的线性空间存储数据，不可以通过[]访问, 不可以通过at访问

*7. 排序*

[示例](../part4/list/example.cpp)



### 4.3.6 [集合--set/multiset](../part4/set/main.cpp)

二叉树结构， 所有的元素会在插入时*自动排序*

区分选择使用: set不允许容器中有重复的元素，而multiset允许容器中有重复的元素; 

*1. 构造函数*
`set<T> st;`            // 类模板实现， 对象的默认构造形式
`set(const set &st);`   // 拷贝构造函数

*2. 赋值assign*
set& operator=(const set &st);

*3. 大小和交换*

成员函数: `empty()`, `size()`, `st1.swap(st2)`

*4. 插入和删除*

成员函数: insert(), erase(), clear()

*5. 查找和统计*

* 对set容器进行查找数据及其统计

find(key);   // 查找key是否存在，若存在，返回*该键的元素迭代器*；若不存在，返回set.end();

count(key);  //  统计key的元素个数

*6. 排序*
set默认从小到大排序， 利用仿函数实现从大到小排序；


#### 4.3.6.1 [对组--pair](../part4/set/pair.cpp)

```
// 第一种方式
pair<string, int>p("momo", 18);
cout << "Name: " << p.first << "\t Age: " << p.second << endl;

// 第二种方式
pair<string, int>p2 = make_pair("momo", 18);
cout << "Name: " << p2.first << "\t Age: " << p2.second << endl;
```


### 4.3.7 [map/multimap](../part4/map/main.cpp)

关联式容器，底层结构为二叉树

map中所有元素都是*pair*

pair中第一个元素为key--检索作用， 第二个元素为value

所有元素都会根据元素的键值自动排序

优点: 可以根据key值快速找到value值

map和multimap区别: map不允许容器中有重复的key, multimap允许容器中有重复的key

*1. 构造函数和赋值*

map<int, int>m1;  // 默认构造 无参构造

map<int, int>m2(m1);  //拷贝构造

m3 = m1;  // 赋值操作

*2. 大小和交换*
成员函数: `inset()` `empty()` `size()` `swap()`


*3. 插入和删除*
insert(elem);     // 在容器中插入元素

clear();          // 消除所有元素

erase();          // 删除pos迭代器所指的元素，返回下一个元素的迭代器  

erase(beg, end);  // 删除区间(beg, end)的所有元素，返回下一个元素的迭代器

erase(key);       // 删除容器中为key的元素  


*4. 查找和统计*

find();           // 查找key是否存在，若存在，返回该键的迭代器；若不存在，返回set.end()

count(key);       // 统计key的元素个数


*5. 排序*


### 4.3.8 [案例员工分组--容器总结](../part4/example_employee_grouping.cpp)









