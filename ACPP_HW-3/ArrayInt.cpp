#include "ArrayInt.h"

ArrayInt::ArrayInt() : m_length(0), m_data(nullptr)
{

}

ArrayInt::ArrayInt(size_t length) : m_length(length)
{
    assert(length >= 0);

    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
}

void ArrayInt::erase()
{
    delete[] m_data;

    m_data = nullptr;
    m_length = 0;
}

int ArrayInt::getLength() const
{
    return m_length;
}

int& ArrayInt::operator[](size_t index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

void ArrayInt::resize(size_t newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data = new int[newLength];

    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        for (int index = 0; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

void ArrayInt::insertBefore(int value, size_t index)
{
    assert(index >= 0 && index <= m_length);

    int* data = new int[m_length + 1];

    for (size_t before = 0; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (size_t after = index; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void ArrayInt::push_back(int value)
{
    insertBefore(value, m_length);
}

void ArrayInt::push_front(int value)
{
    insertBefore(value, 0);
}

void ArrayInt::pop_back()
{
    resize(m_length - 1);
}

void ArrayInt::pop_front()
{
    if (m_length - 1 <= 0)
    {
        erase();
        return;
    }

    int* data = new int[m_length - 1];

    if (m_length > 0)
    {
        for (size_t index = 1; index < m_length; ++index)
            data[index] = m_data[index];
    }


    delete[] m_data;

    m_data = data;
    m_length--;
}

void ArrayInt::sort()
{
    int key = 0;
    int i = 0;
    for (size_t j = 1; j < m_length; j++) {
        key = m_data[j];
        i = j - 1;
        while (i >= 0 && m_data[i] > key) {
            m_data[i + 1] = m_data[i];
            i = i - 1;
            m_data[i + 1] = key;
        }
    }
}

void ArrayInt::print() const
{
    std::cout << "[ ";
    for (size_t index = 0; index < m_length; ++index)
    {
        std::cout << m_data[index] << " ";
    }
    std::cout << "]" << std::endl;
}

ArrayInt::iterator ArrayInt::begin()
{
    return iterator(m_data);
}

ArrayInt::iterator ArrayInt::end()
{
    return iterator(m_data + m_length);
}

ArrayInt::const_iterator ArrayInt::begin() const
{
    return const_iterator(m_data);
}

ArrayInt::const_iterator ArrayInt::end() const
{
    return const_iterator(m_data + m_length);
}

ArrayInt::~ArrayInt()
{
	delete[] m_data;
}
