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
        : _m_max_size(__n)
    {
    }
    
    recent(const std::initializer_list<value_type> &__il)
        : _m_max_size(10)
    {
        for (const auto &i : __il)
            _m_datas.push_front(i);
        resize(10);
    }

    void push(const value_type &__x)
    {
        while (_m_datas.size() >= _m_max_size)
            _m_datas.pop_back();
        _m_datas.push_front(__x);
    }

    void pop()
    {
        _m_datas.pop_back();
    }

    reference front() noexcept
    {
        return *_m_datas.begin();
    }

    const_reference front() const noexcept
    {
        return *_m_datas.begin();
    }

    reference back() noexcept
    {
        iterator __t = _m_datas.end();
        --__t;
        return *__t;
    }

    const_reference back() const noexcept
    {
        const_iterator __t = _m_datas.end();
        --__t;
        return *__t;
    }

    iterator begin() noexcept
    {
        return _m_datas.begin();
    }

    const_iterator begin() const
    {
        return _m_datas.begin();
    }

    iterator end() noexcept
    {
        return _m_datas.end();
    }

    const_iterator end() const noexcept
    {
        return _m_datas.end();
    }

    size_type size() const noexcept
    {
        return _m_datas.size();
    }

    void clear() noexcept
    {
        _m_datas.clear();
    }

    void resize(size_type __n)
    {
        _m_max_size = __n;
        while (_m_datas.size() > _m_max_size)
            _m_datas.pop_back();
    }

    bool empty() const noexcept
    {
        return _m_datas.empty();
    }

private:
    datas_type _m_datas;
    size_type _m_max_size;
};

#endif // RECENT_HPP