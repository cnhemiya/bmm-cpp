# string_split 说明书

## 介绍

将一个字符串按照 __sep 分割成一个字符串容器。  
返回的字符串容器，符合 STL 的 std::vector 容器类型，而且必须是一个类型为 _String 的容器。

## 原型

```c++
/// @fn _ArrayT string_split(const _String &__s, const _String &__sep)
/// @brief 将一个字符串按照 __sep 分割成一个字符串容器
/// @details 返回的字符串容器，符合 STL 的 std::vector 容器类型，而且必须是一个类型为 _String 的容器
///
/// @param __s 字符串
/// @param __sep 分隔符
///
/// @return 字符串容器
template<typename _String, typename _ArrayT = std::vector<_String>>
_ArrayT string_split(const _String &__s, const _String &__sep);
```

## 依赖

**C++ STL 标准模板库**

## 相关说明

|名称|说明|
|--|--|
|头文件|[<bmm/string_algo.hpp>](/bmm/string_algo.hpp)|
|名字空间|bmm::string_split|
|说明书|[string_split](/doc/manual/string_split.md)|

## 示例

```c++
#include <iostream>
#include <vector>
#include <string>
#include "bmm/string_algo.hpp"

int main(int argc, const char *argv[])
{
    std::string s = "hello,world,cpp";
    std::cout << "string = " << s << std::endl;
    auto split = bmm::string_split(s, std::string(","));
    std::cout << "string_split result: " << std::endl;
    for (const auto &i : split)
        std::cout << i << std::endl;
    return 0;
}
```

## 结果

```text
string = hello,world,cpp
string_split result: 
hello
world
cpp
```
