#!/bin/bash
#在文件2080中输入字符串Hello World
echo Hello World > 2080
#以只读形式打开文件2080，并编号为3
exec 3<2080
#读入文件3中的所有内容到数组myarray中，以空格分隔的不同单词表示不同变量。
#&符号意思是后面的内容代表一个文件。
read -a myarray <&3
#关闭文件3
exec 3>&-
#输出数组
echo ${myarray[@]} | xargs -n 1