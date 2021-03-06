/// LICENSE  MulanPSL2
/// @author  cnhemiya@qq.com
/// @date    2022-02-06 15:58
///
/// @file bmm/algo.hpp
/// @brief 一些算法

#ifndef _BMM_ALGO_HPP_
#define _BMM_ALGO_HPP_

#include <algorithm>
#include "global.hpp"

_BMM_NAMESPACE_BEGIN_

/// @fn bool is_in(const _ArrayT &__arr, const _T &__val)
/// @brief 判断 value 是否在容器中
/// @details _ArrayT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器
///
/// @param __arr 容器
/// @param __val 值
///
/// @return 是否在容器中
template <typename _ArrayT, typename _T>
bool is_in(const _ArrayT &__arr, const _T &__val)
{
    return std::find(__arr.begin(), __arr.end(), __val) != __arr.end();
}

/// @fn bool if_in(_ArrayT &__arr, const _T &__val, _Func __func)
/// @brief 如果找到第一个符合条件的值，则调用函数 __func 并返回 true，否则返回 false
/// @details _ArrayT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器
///
/// @param __arr 容器
/// @param __val 值
/// @param __func 函数，符合 void(_T &) 的函数，可以是 lambda 表达式，并且可以更改容器中的值
///
/// @return 是否在容器中
template <typename _ArrayT, typename _T, typename _Func = std::function<void(_T &)>>
bool if_in(_ArrayT &__arr, const _T &__val, _Func __func)
{
    auto __it = std::find(__arr.begin(), __arr.end(), __val);
    if (__it != __arr.end())
    {
        __func(*__it);
        return true;
    }
    return false;
}

_BMM_NAMESPACE_END_

#endif // _BMM_ALGO_HPP_