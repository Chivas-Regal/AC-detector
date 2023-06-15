<h1 align="center">AC对拍器</h1>

## 文件填写方式

在 `input_maker.cpp` 中按题目要求用 C++ 输出一个样例的数据（随机数一定要 `srand(time(NULL))` 一下    
在 `solve_mine.cpp` 中填入自己的解题代码  
在 `solve_others.cpp` 中填入标答的解题代码  
按上述运行方式运行  

若返回 `Wrong Answer in test <id>`  
请进 
- `dst/sample<id>/input.txt` 看出错的输入  
- `dst/sample<id>/output_mine.txt` 看自己的输出  
- `dst/sample<id>/output_others.txt` 看标答的输出  

> 已经在三个文件里面给出了一份和标答相异输出的示例

## 运行方式

环境内有 `bash` 的在终端写   

```sh
bash run.sh
```

否则进入本项目目录后运行  

```sh
g++ work/main.cpp -o work/main -std=c++11
work/main
```

## 功能需求

这是作者在下班之余简单构思一会儿完成的小玩具，辅助功能较少。  
存在 “功能需求” 或者 “造数据的辅助工具” 的 uu 请联系作者：1411390466@qq.com  
或者 
- +Q: 1411390466
- +V: zyz1411390466  

我们一起探讨  
  
> 目前不支持 RE 的报错，但 RE 报错会在 `Wrong Answer` 前被本机电脑指出

## 原理

用 C++ 内置的 `system()` 函数运行十次，即每次都能完成数据、变量、代码的隔离    
每次先执行 `input_maker.cpp` 打印输入数据到一个输入文件    
然后再执行两份解题代码，读取输入文件内容，各自打印到一个输出文件  
最后进行比对判断输出是否相同  
  
## 作者注语

以前自己写题要对拍的时候用单文件还要写 `namespace` 分域同名变量，还要每次都初始化，需要手动改的地方太多了。  
这里只需要将你的代码粘贴进 `solve_mine.cpp` ，将别人的代码粘贴进 `solve_others.cpp`  
然后按题目要求在 `input_maker.cpp` 中输出合法的 “输入数据” 即可，不涉及什么初始化、变量重名等问题。