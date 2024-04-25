#pragma once
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>


class CustomArray {
public:

    typedef unsigned int UINT;
    typedef double value_type;
    typedef double* iterator;
    typedef const double* const_iterator;
    typedef double& reference;
    typedef const double& const_reference;
    typedef std::size_t size_type;

private:

    static const size_type min_size = 10; // ��������� ����� ������
    size_type size; // ������� ����� ��� ��������
    size_type count; // ������� �������� � �����
    size_type first; // �������� ������� ������� �������� � �����
    value_type* elems; // �������� �� ���

public:

    // ������������/���������/����������
    CustomArray();
    CustomArray(const CustomArray& other);
    ~CustomArray();

    // ���������
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    // ������
    size_type getSize() const;
    size_type getCapacity() const;
    bool empty() const;

    // ������ �� ��������
    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    value_type* processArray(const value_type* arr, size_type size, size_type& newSize);

    // ������-������������
    void push_back(const value_type& value);
    void pop_back();
    void resize(size_type newSize);
    void reserve(size_type newCapacity);
    void clear();

    // ����� ������� �����/������
    friend std::istream& operator>>(std::istream& input, CustomArray& arr);
    friend std::ostream& operator<<(std::ostream& output, const CustomArray& arr);
};