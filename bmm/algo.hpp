#ifndef _JYCPP_ALGO_HPP_
#define _JYCPP_ALGO_HPP_

#include "global.hpp"

_JYCPP_NAMESPACE_BEGIN_

/// @brief 判断 value 是否在容器中中
///
/// @param __arr 容器
/// @param __val 值
///
/// @return 是否在容器中
///
/// ArryaT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器
/// @code
/// std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
/// if (is_in(vec, 5))
///     cout << "5 is in vec" << endl;
/// else
///     cout << "5 is not in vec" << endl;
/// @endcode
template <typename _ArrayT, typename _T>
bool is_in(const _ArrayT &__arr, const _T &__val)
{
    return std::find(__arr.begin(), __arr.end(), __val) != __arr.end();
}

/// @brief 如果 value 在容器中则，调用函数 __func 并返回 true，否则返回 false
///
/// @param __arr 容器
/// @param __val 值
/// @param __func 函数，符合 void(_T &) 的函数，可以是 lambda 表达式，并且可以更改容器中的值
///
/// @return 是否在容器中
///
/// ArryaT 必须是一个符合 STL 的容器类型，而且必须是一个类型为 _T 的容器
/// @code
/// std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
/// if_in(vec, 5, [](const int &i){ cout << i << " is in \n"; });
/// @endcode
template <typename _ArrayT, typename _T, typename _Func = std::function<void(_T &)>>
bool if_in(_ArrayT &__arr, const _T &__val, _Func __func)
{
    auto it = std::find(__arr.begin(), __arr.end(), __val);
    if (it != __arr.end())
    {
        __func(*it);
        return true;
    }
    return false;
}

_JYCPP_NAMESPACE_END_

#endif // _JYCPP_ALGO_HPP_