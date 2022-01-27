#ifndef RECENT_HPP
#define RECENT_HPP
#include <list>

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

    recent(size_type __n = 10)
        : _M_max_size(__n)
    {
    }

    recent(const std::initializer_list<value_type> &__il)
        : _M_max_size(10)
    {
        for (const auto &i : __il)
            _M_datas.push_front(i);
        resize(10);
    }

    void push(const value_type &__x)
    {
        while (_M_datas.size() >= _M_max_size)
            _M_datas.pop_back();
        _M_datas.push_front(__x);
    }

    void pop()
    {
        _M_datas.pop_back();
    }

    reference front() noexcept
    {
        return *_M_datas.begin();
    }

    const_reference front() const noexcept
    {
        return *_M_datas.begin();
    }

    reference back() noexcept
    {
        iterator __tmp = _M_datas.end();
        --__tmp;
        return *__tmp;
    }

    const_reference back() const noexcept
    {
        const_iterator __tmp = _M_datas.end();
        --__tmp;
        return *__tmp;
    }

    iterator begin() noexcept
    {
        return _M_datas.begin();
    }

    const_iterator begin() const
    {
        return _M_datas.begin();
    }

    iterator end() noexcept
    {
        return _M_datas.end();
    }

    const_iterator end() const noexcept
    {
        return _M_datas.end();
    }

    iterator rbegin() noexcept
    {
        return _M_datas.rbegin();
    }

    const_iterator rbegin() const noexcept
    {
        return _M_datas.rbegin();
    }

    iterator rend() noexcept
    {
        return _M_datas.rend();
    }

    const_iterator rend() const noexcept
    {
        return _M_datas.rend();
    }

    size_type size() const noexcept
    {
        return _M_datas.size();
    }

    size_type max_size() const noexcept
    {
        return _M_max_size;
    }

    void clear() noexcept
    {
        _M_datas.clear();
    }

    void resize(size_type __n)
    {
        _M_max_size = __n;
        while (_M_datas.size() > _M_max_size)
            _M_datas.pop_back();
    }

    bool empty() const noexcept
    {
        return _M_datas.empty();
    }

private:
    datas_type _M_datas;
    size_type _M_max_size;
};

#endif // RECENT_HPP