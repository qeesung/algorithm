
```cpp
├── dataNode.cc 数据节点源文件
├── dataNode.h 数据节点头文件
├── directAddr.cc 直接寻址法源文件
├── directAddr.h 直接寻址法的头文件
├── directAddr_test.cc cppunit测试直接寻址源文件
├── directAddr_test.h cppunit测试设备的定义头文件
├── main.cc 测试主文件
├── Makefile
└── README.md
0 directories, 9 files
```

#编译方法

- 如果你的电脑有`cppunit`的动态链接库
```bash
make 
```
- 如果没有`cppunit`的动态链接库,你可以在你的源文件yourSourceFile.cc里面包含`#include "directAddr.h"`,就可以使用直接寻址表
```bash
g++ yourSourceFile.cc -o target
```

#执行程序
```bash
./testDirectAddr(or ./yourTarget)
```

