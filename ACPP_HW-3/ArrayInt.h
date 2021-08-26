#pragma once

#include <cassert>
#include <iostream>
#include "ArrIterator.h"

class ArrayInt
{
private:
    size_t m_length;
    int* m_data;
public:
    typedef ArrIterator<int> iterator;
    typedef ArrIterator<const int> const_iterator;

    ArrayInt();

    ArrayInt(size_t length);

    void erase();

    int getLength() const;

    int& operator[](size_t index);

    void resize(size_t newLength);

    void insertBefore(int value, size_t index);

    void push_back(int value);
    void push_front(int value);

    void pop_back();
    void pop_front();

    void sort();

    void print() const;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    ~ArrayInt();

};


