/// ======================================================================
/// @license MulanPSL2
/// @author  cnhemiya@qq.com
/// @date    2022-02-06 15:59
/// ======================================================================
/// @file recent.hpp
/// @brief 最近使用的元素

#ifndef _BMM_RECENT_HPP_
#define _BMM_RECENT_HPP_

#include <list>
#include "global.hpp"

_BMM_NAMESPACE_BEGIN_

/// @brief 最近使用的元素
/// 默认情况下最大保存10个最近使用的元素，最近使用的元素会被放在最前面，并且只保留最近使用的元素。
/// 如果最近使用的元素超过了最大保存数量，则最后一个元素会被删除。
///
/// @tparam _T 元素类型
///
/// @example 示例：
/// @code
/// #include <iostream>
/// #include <bmm/recent.hpp>
///
/// int main(int argc, const char *argv[])
/// {
///     bmm::recent<int> rec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
///     for (auto i : rec)
///         std::cout << i << " ";
///     std::cout << std::endl;
///     rec.push(50);
///     for (auto i : rec)
///         std::cout << i << " ";
///     std::cout << std::endl;
///     return 0;
/// }
/// @endcode

template <typename _T>
class recent
{
public:
    typedef _T value_type;
    typedef typename std::list<value_type> datas_type;
    typedef typename datas_type::size_type size_type;
    typedef typename datas_type::reference reference;
    typedef typename datas_type::const_reference const_reference;
    typedef typename datas_type::iterator iterator;
    typedef typename datas_type::const_iterator const_iterator;
    typedef typename datas_type::reverse_iterator reverse_iterator;
    typedef typename datas_type::const_reverse_iterator const_reverse_iterator;

    /// @brief 构造函数
    ///
    /// @param max_size 最大保存的最近使用的类的个数，默认为10
    recent(size_type __n = 10)
        : _M_max_size(__n)
    {
    }

    /// @brief 构造函数
    ///
    /// @param __l 要构造的最近使用的类的初始化列表
    recent(const std::initializer_list<value_type> &__l)
        : _M_max_size(10)
    {
        for (const auto &i : __l)
            _M_datas.push_front(i);
        resize(10);
    }

    /// @brief 向前压入元素
    void push(const value_type &__x)
    {
        while (_M_datas.size() >= _M_max_size)
            _M_datas.pop_back();
        _M_datas.push_front(__x);
    }

    /// @brief 向前压入元素
    void push(value_type &&__x)
    {
        while (_M_datas.size() >= _M_max_size)
            _M_datas.pop_back();
        _M_datas.push_front(std::move(__x));
    }

    /// @brief 弹出最后一个元素
    void pop()
    {
        _M_datas.pop_back();
    }

    /// @brief 弹出第一个元素的引用
    reference front() noexcept
    {
        return *_M_datas.begin();
    }

    /// @brief 弹出第一个元素的常引用
    const_reference front() const noexcept
    {
        return *_M_datas.begin();
    }

    /// @brief 弹出最后一个元素的引用
    reference back() noexcept
    {
        iterator __tmp = _M_datas.end();
        --__tmp;
        return *__tmp;
    }

    /// @brief 弹出最后一个元素的常引用
    const_reference back() const noexcept
    {
        const_iterator __tmp = _M_datas.end();
        --__tmp;
        return *__tmp;
    }

    /// @brief 返回迭代器第一个指针
    iterator begin() noexcept
    {
        return _M_datas.begin();
    }

    /// @brief 返回迭代器第一个常指针
    const_iterator begin() const
    {
        return _M_datas.begin();
    }

    /// @brief 返回迭代器最后一个指针
    iterator end() noexcept
    {
        return _M_datas.end();
    }

    /// @brief 返回迭代器最后一个常指针
    const_iterator end() const noexcept
    {
        return _M_datas.end();
    }

    /// @brief 返回反向迭代器第一个指针
    iterator rbegin() noexcept
    {
        return _M_datas.rbegin();
    }

    /// @brief 返回反向迭代器第一个常指针
    const_iterator rbegin() const noexcept
    {
        return _M_datas.rbegin();
    }

    /// @brief 返回反向迭代器最后一个指针
    iterator rend() noexcept
    {
        return _M_datas.rend();
    }

    /// @brief 返回反向迭代器最后一个常指针
    const_iterator rend() const noexcept
    {
        return _M_datas.rend();
    }

    /// @brief 返回元素数量
    size_type size() const noexcept
    {
        return _M_datas.size();
    }

    /// @brief 返回最大元素数量
    size_type max_size() const noexcept
    {
        return _M_max_size;
    }

    /// @brief 清除容器里所有元素
    void clear() noexcept
    {
        _M_datas.clear();
    }

    /// @brief 重置容器的最大元素数量
    ///
    /// @param __n 新的最大元素数量
    void resize(size_type __n)
    {
        _M_max_size = __n;
        while (_M_datas.size() > _M_max_size)
            _M_datas.pop_back();
    }

    /// @brief 判断容器是否为空
    bool empty() const noexcept
    {
        return _M_datas.empty();
    }

private:
    /// @brief 容器
    datas_type _M_datas;

    /// @brief 容器的最大元素数量
    size_type _M_max_size;
};

_BMM_NAMESPACE_END_

#endif // _BMM_RECENT_HPP_