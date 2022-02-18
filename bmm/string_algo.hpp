/// LICENSE  MulanPSL2
/// @author  cnhemiya@qq.com
/// @date    2022-02-18 10:22
///
/// @file bmm/string_algo.hpp
/// @brief 字符串一些算法

#ifndef _BMM_STRING_ALGO_HPP_
#define _BMM_STRING_ALGO_HPP_

#include "global.hpp"

_BMM_NAMESPACE_BEGIN_

/// @fn _String string_join(_InputIterator __first, _InputIterator __last, const _String &__sep)
/// @brief 将一个范围内的字符串连接成一个字符串
/// @details 返回的字符串中，每个字符串之间用 __sep 分隔
///
/// @param __first 范围的开始迭代器
/// @param __last 范围的结束迭代器
/// @param __sep 分隔符
///
/// @return 连接后的字符串
template <typename _InputIterator, typename _String>
_String string_join(_InputIterator __first, _InputIterator __last, const _String &__sep)
{
    _String __s;
    if (__first != __last)
        __s = *__first++;
    for (; __first != __last; ++__first)
        __s += __sep + *__first;
    return __s;
}

/// @fn _String string_join(const _ArrayT &__arr, const _String &__sep)
/// @brief 将一个容器内的字符串连接成一个字符串
/// @details 返回的字符串中，每个字符串之间用 __sep 分隔， \n
/// 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _String 的容器
///
/// @param __arr 符合 STL 的容器类型
/// @param __sep 分隔符
///
/// @return 连接后的字符串
template <typename _ArrayT, typename _String>
_String string_join(const _ArrayT &__arr, const _String &__sep)
{
    return string_join(__arr.begin(), __arr.end(), __sep);
}

_BMM_NAMESPACE_END_

#endif // _BMM_STRING_ALGO_HPP_
