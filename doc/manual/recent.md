# recent 说明书

## 介绍

最近使用的元素。  
默认情况下最大保存10个最近使用的元素，最近使用的元素会被放在最前面，并且只保留最近使用的元素。  
如果最近使用的元素超过了最大保存数量，则最后一个元素会被删除。

## 原型

```c++
/// @brief 最近使用的元素。
/// @details 默认情况下最大保存10个最近使用的元素，最近使用的元素会被放在最前面，并且只保留最近使用的元素。 \n
/// 如果最近使用的元素超过了最大保存数量，则最后一个元素会被删除。
///
/// @tparam _T 元素类型
template <typename _T>
class recent;
```

## 依赖

**C++ STL 标准模板库**

## 相关说明

名称|说明
--|--
头文件|[<bmm/recent.hpp>](/bmm/recent.hpp)
名字空间|bmm::recent
说明书|[recent](/doc/manual/recent.md)

## 示例

```c++
#include <iostream>
#include <vector>
#include "bmm/recent.hpp"

int main(int argc, const char *argv[])
{
    bmm::recent<int> rec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "recent example begin" << std::endl;
    std::cout << "recent before: ";
    for (auto i : rec)
        std::cout << i << " ";
    std::cout << std::endl;
    rec.push(50);
    std::cout << "push 50" << std::endl;
    std::cout << "recent after: ";
    for (auto i : rec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "recent example end" << std::endl;
}
```

## 结果

```bash
recent example begin
recent before: 10 9 8 7 6 5 4 3 2 1 
push 50
recent after: 50 10 9 8 7 6 5 4 3 2 
recent example end
```
