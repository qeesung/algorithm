```
.
├── hash_table.cc 散列表源文件
├── hash_table.h 散列表头文件
├── hash_table_test.cc 散列表测试源文件
├── hash_table_test.h 散列表测试头文件
├── link_list.cc 链式链表源文件
├── link_list.h 链式链表头文件
├── list.h 链表接口文件
├── main.cc 主测试文件
├── Makefile
└── README.md

0 directories, 10 files
```

#编译方法

如果你安装了`cppunit` 

```
make
```

- 如果没有安装`cppunit`，你需要这样编译
```
g++ hash_table_test.cc youSourceFile.cc -o target
```

#运行方法
```
./hashTest(or your target)
```

