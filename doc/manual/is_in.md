# is_in 说明书

## 介绍

判断 value 是否在容器中  
_ArrayT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器

## 原型

```c++
/// @brief 判断 value 是否在容器中
/// @details _ArrayT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器
///
/// @param __arr 容器
/// @param __val 值
///
/// @return 是否在容器中
template <typename _ArrayT, typename _T>
bool is_in(const _ArrayT &__arr, const _T &__val);
```

## 依赖

**C++ STL 标准模板库**

## 相关说明

|名称|说明|
|--|--|
|头文件|[<bmm/algo.hpp>](/bmm/algo.hpp)|
|名字空间|bmm::is_in|
|说明书|[is_in](/doc/manual/is_in.md)|

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
    std::cout << "is_in example begin" << std::endl;
    std::cout << "vector: ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "is_in(vec, 1) = " << to_string(bmm::is_in(vec, 1)) << std::endl;
    std::cout << "is_in(vec, 11) = " << to_string(bmm::is_in(vec, 11)) << std::endl;
    std::cout << "is_in example end" << std::endl;
    return 0;
}
```

## 结果

```text
is_in example begin
vector: 1 2 3 4 5 6 7 8 9 10 
is_in(vec, 1) = true
is_in(vec, 11) = false
is_in example end
```
