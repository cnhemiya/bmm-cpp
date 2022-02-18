# string_join 说明书

## 介绍

将一个范围内的字符串连接成一个字符串，返回的字符串中，每个字符串之间用 __sep 分隔。  
或者，将一个容器内的字符串连接成一个字符串，返回的字符串中，每个字符串之间用 __sep 分隔。 

## 原型

```c++
/// @brief 将一个范围内的字符串连接成一个字符串
/// @details 返回的字符串中，每个字符串之间用 __sep 分隔
///
/// @param __first 范围的开始迭代器
/// @param __last 范围的结束迭代器
/// @param __sep 分隔符
///
/// @return 连接后的字符串
template <typename _InputIterator, typename _String>
_String string_join(_InputIterator __first, _InputIterator __last, const _String &__sep);

/// @brief 将一个容器内的字符串连接成一个字符串
/// @details 返回的字符串中，每个字符串之间用 __sep 分隔， \n
/// 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _String 的容器
///
/// @param __arr 符合 STL 的容器类型
/// @param __sep 分隔符
///
/// @return 连接后的字符串
template <typename _ArrayT, typename _String>
_String string_join(const _ArrayT &__arr, const _String &__sep);
```

## 依赖

**C++ STL 标准模板库**

## 相关说明

|名称|说明|
|--|--|
|头文件|[<bmm/string_join.hpp>](/bmm/string_join.hpp)|
|名字空间|bmm::string_join|
|说明书|[string_join](/doc/manual/string_join.md)|

## 示例

```c++
#include <iostream>
#include <vector>
#include <string>
#include "bmm/string_algo.hpp"

int main(int argc, const char *argv[])
{
    std::vector<std::string> v = {"hello", "world", "cpp"};
    std::cout << "string_join -- : " 
        << bmm::string_join(v.begin(), v.end(), std::string("--")) << std::endl;
    std::cout << "string_join ,  : " 
        << bmm::string_join(v, std::string(",")) << std::endl;
    return 0;
}
```

## 结果

```text
string_join -- : hello--world--cpp
string_join ,  : hello,world,cpp
```
