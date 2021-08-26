#pragma once

template<typename ValueType>
class ArrIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
    friend class ArrayInt;
private:
    ArrIterator(ValueType* p);
public:
    ArrIterator(const ArrIterator& it);

    bool operator!=(ArrIterator const& other) const;
    bool operator==(ArrIterator const& other) const;
    typename ArrIterator<ValueType>::reference operator*() const;
    ArrIterator& operator++();
private:
    ValueType* p;
};


template<typename ValueType>
ArrIterator<ValueType>::ArrIterator(ValueType* p) : p(p)
{
}

template<typename ValueType>
ArrIterator<ValueType>::ArrIterator(const ArrIterator& it) : p(it.p)
{
}

template<typename ValueType>
bool ArrIterator<ValueType>::operator!=(ArrIterator const& other) const
{
    return p != other.p;
}

template<typename ValueType>
bool ArrIterator<ValueType>::operator==(ArrIterator const& other) const
{
    return p == other.p;
}

template<typename ValueType>
typename ArrIterator<ValueType>::reference ArrIterator<ValueType>::operator*() const
{
    return *p;
}

template<typename ValueType>
ArrIterator<ValueType>& ArrIterator<ValueType>::operator++()
{
    ++p;
    return *this;
}
