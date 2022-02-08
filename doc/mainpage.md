@mainpage 使用说明
# 苞米面 C++ 模板库

## 简介
苞米面 C++ 模板库，无需编译，直接包含头文件就可以。  
所有模板类和算法都包含在 **bmm** 名字空间里，例如： **bmm::recent**。  
需要 C++ 编译器，支持 **C++17** 标准，只依赖 **C++ STL 标准模板库**。

## 依赖
**C++ STL 标准模板库**

## 使用说明 
详细情况查看 **doc/html** 里的文档。  

**示例代码**
```c++
#include <iostream>
#include <vector>
#include "bmm/recent.hpp"
#include "bmm/algo.hpp"

int main(int argc, const char *argv[])
{
    bmm::recent<int> rec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "recent example begin" << std::endl;
    std::cout << "before recent: ";
    for (auto i : rec)
        std::cout << i << " ";
    std::cout << std::endl;
    rec.push(50);
    std::cout << "push 50" << std::endl;
    std::cout << "after recent: ";
    for (auto i : rec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "recent example end" << std::endl;
    
    std::cout << std::endl;
    std::cout << "algo example begin" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 3;
    if (bmm::is_in(vec, n))
        std::cout << "is_in: " << n << " is in vec" << std::endl;
    else
        std::cout << "is_in: " << n << " is not in vec" << std::endl;
    int k = 10;
    int add = 50;
    std::cout << "if_in before: ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    bmm::if_in(vec, k, [add](int &i)
               { i += add; });
    std::cout << "if_in " << k << " += " << add << ": ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "algo example end" << std::endl;
    return 0;
}
```

**结果**
```bash
recent example begin
before recent: 10 9 8 7 6 5 4 3 2 1 
push 50
after recent: 50 10 9 8 7 6 5 4 3 2 
recent example end

algo example begin
is_in: 3 is in vec
if_in before: 1 2 3 4 5 6 7 8 9 10 
if_in 10 += 50: 1 2 3 4 5 6 7 8 9 60 
algo example end
```
## 功能说明
所有模板类和算法都包含在 **bmm** 名字空间里，例如： **bmm::recent**
### 模板类
名称|文件|说明
--|--|--
recent|<bmm/recent.hpp>|最近使用的元素，类似于 最近使用的文件

### 算法
名称|文件|说明
--|--|--
is_in|<bmm/algo.hpp>|判断 value 是否在容器中  
if_in|<bmm/algo.hpp>|如果 value 在容器中则，调用函数 __func 并返回 true，否则返回 false

## 开源协议
[MulanPSL-2.0](http://license.coscl.org.cn/MulanPSL2)

## 项目地址
**GITEE**&nbsp;&nbsp;&nbsp;&nbsp;**https://gitee.com/cnhemiya/bmm-cpp**