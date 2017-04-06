0)这是什么及如何使用
	本软件实现了“图书管理系统”，协助用户进行相关信息的管理。
	本软件支持图书的“增添”“删除”“借阅”“归还”“信息查询”等功能

	Windows：
	直接运行/bin/LibrarySystem.exe 即可打开系统，并根据提示进行操作
	Linux:
	阅读 /src/Readme.txt并根据其中的编译指令进行编译和运行文件
	运行后输入help可查看帮助

1）各个文件的包含关系：（a before b 表示需先编译a才能编译b）
	详情请见 /src/Readme.txt 及文档

	MyLibrary.h before MyLibrary.cpp
	frame.h and MyLibrary.h and MyLibrary.cpp before frame.cpp
	all files before main.cpp
	

2）各个文件的用途简介：
类实现部分：
	MyLibrary.h
		包含两个Book 和 Library 两个class的定义， 并实现部分inline函数
	MyLibrary.cpp
		实现对上述头文件的各种函数

类使用部分：	
	frame.h
		定义了main函数中所使用的所有函数，实现部分inline函数
		定义了若干有用的常量
		函数大多数与输出有关（Print_*）
		函数间具体关系请见文档
	frame.cpp
		实现上一头文件的所有函数
 	main.cpp
		使用正则实现了简单的用户交互界面
		包含以上所有文件（四个）
		
3）注意事项：
	“类实现部分”不实现任何输出函数，只实现了与类与用户“信息交换”相关的函数。对输出的具体		实现见“类使用部分”

	不建议修改“类实现”部分的代码，除非你清楚它的实现逻辑
	可根据输出格式、实际使用的需要修改“类使用部分”的代码

	frame.h与frame.cpp中包含了所有的格式化输出函数，用户可以按需修改其中的输出格式，详情见文		档

4)github: YanB25

5)更新日志：
	v2.0:更改了main.cpp中对书名的格式限制。允许书名中带有空格，但仍要求书名只含有大小写			字母、数字或下划线，且数字不能开头。

	v3.0:更改了MyLibrary.cpp文件，修复了“当书名中带有空格时文件储存出错”这一bug