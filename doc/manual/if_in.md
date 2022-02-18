# if_in 说明书

## 介绍

如果找到第一个符合条件的值，则调用函数 __func 并返回 true，否则返回 false  
_ArrayT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器

## 原型

```c++
/// @brief 如果找到第一个符合条件的值，则调用函数 __func 并返回 true，否则返回 false
/// @details _ArrayT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器
///
/// @param __arr 容器
/// @param __val 值
/// @param __func 函数，符合 void(_T &) 的函数，可以是 lambda 表达式，并且可以更改容器中的值
///
/// @return 是否在容器中
template <typename _ArrayT, typename _T, typename _Func = std::function<void(_T &)>>
bool if_in(_ArrayT &__arr, const _T &__val, _Func __func);
```

## 依赖

**C++ STL 标准模板库**

## 相关说明

|名称|说明|
|--|--|
|头文件|[<bmm/algo.hpp>](/bmm/algo.hpp)|
|名字空间|bmm::if_in|
|说明书|[if_in](/doc/manual/if_in.md)|

## 示例

```c++
#include <iostream>
#include <vector>
#include <string>
#include "bmm/algo.hpp"

std::string to_string(bool b)
{
    return b ? "true" : "false";
}

int main(int argc, const char *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "if_in example begin" << std::endl;
    std::cout << "vector before: ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "if 10 is in: "
              << to_string(bmm::if_in(vec, 10, [](int &i)
                                      { i = i + 1; }))
              << std::endl;
    std::cout << "10 += 1 " << std::endl;
    std::cout << "vector after:  ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "if_in example end" << std::endl;
    return 0;
}
```

## 结果

```text
if_in example begin
vector before: 1 2 3 4 5 6 7 8 9 10 
if 10 is in: true
10 += 1 
vector after:  1 2 3 4 5 6 7 8 9 11 
if_in example end
```
