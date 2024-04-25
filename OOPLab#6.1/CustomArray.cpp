#include "CustomArray.h"

CustomArray::CustomArray() : size(min_size), count(0), first(0), elems(new value_type[min_size]) {}

CustomArray::CustomArray(const CustomArray& other) : size(other.size), count(other.count), first(other.first), elems(new value_type[other.size]) {
    std::copy(other.elems, other.elems + other.size, elems);
}

CustomArray::~CustomArray() {
    delete[] elems;
}

CustomArray::iterator CustomArray::begin() {
    return elems + first;
}

CustomArray::iterator CustomArray::end() {
    return elems + first + count;
}

CustomArray::const_iterator CustomArray::cbegin() const {
    return elems + first;
}

CustomArray::const_iterator CustomArray::cend() const {
    return elems + first + count;
}

CustomArray::size_type CustomArray::getSize() const {
    return count;
}

CustomArray::size_type CustomArray::getCapacity() const {
    return size;
}

bool CustomArray::empty() const {
    return count == 0;
}

CustomArray::reference CustomArray::operator[](size_type index) {
    return elems[first + index];
}

CustomArray::const_reference CustomArray::operator[](size_type index) const {
    return elems[first + index];
}

CustomArray::reference CustomArray::front() {
    return elems[first];
}

CustomArray::const_reference CustomArray::front() const {
    return elems[first];
}

CustomArray::reference CustomArray::back() {
    return elems[first + count - 1];
}

CustomArray::const_reference CustomArray::back() const {
    return elems[first + count - 1];
}

CustomArray::value_type* CustomArray::processArray(const value_type* arr, size_type size, size_type& newSize) {

    value_type* newArray = new value_type[size];
    std::copy(arr, arr + size, newArray);
    newSize = size;

    return newArray;
}

void CustomArray::push_back(const value_type& value) {
    if (count == size) {
        reserve(size * 2);
    }
    elems[first + count] = value;
    count++;
}

void CustomArray::pop_back() {
    if (!empty()) {
        count--;
    }
}

void CustomArray::resize(size_type newSize) {
    if (newSize > size) {
        reserve(newSize);
    }
    count = std::min(count, newSize);
}

void CustomArray::reserve(size_type newCapacity) {
    if (newCapacity > size) {
        size = newCapacity;
        value_type* newElems = new value_type[size];
        std::copy(elems + first, elems + first + count, newElems);
        delete[] elems;
        elems = newElems;
        first = 0;
    }
}

void CustomArray::clear() {
    count = 0;
}

std::istream& operator>>(std::istream& input, CustomArray& arr) {
    for (CustomArray::size_type i = 0; i < arr.getSize(); ++i) {
        input >> arr[i];
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const CustomArray& arr) {
    for (CustomArray::size_type i = 0; i < arr.getSize(); ++i) {
        output << arr[i] << " ";
    }
    return output;
}

CustomArray::value_type* createDynamicArray(const CustomArray::value_type* arr, CustomArray::size_type size, CustomArray::size_type& newSize) {
    CustomArray::value_type* resultArray = new CustomArray::value_type[size];
    newSize = size;
    CustomArray::value_type maxElement = arr[0];
    for (CustomArray::size_type i = 0; i < size; ++i) {
        resultArray[i] = arr[i];
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    for (CustomArray::size_type i = 0; i < newSize; ++i) {
        resultArray[i] -= maxElement;
    }

    CustomArray::value_type sum = 0;
    for (CustomArray::size_type i = 0; i < newSize; ++i) {
        sum += std::abs(resultArray[i]);
    }
    CustomArray::value_type average = sum / newSize;

    newSize += 2;
    CustomArray::value_type* tempArray = new CustomArray::value_type[newSize];
    std::copy(resultArray, resultArray + newSize - 2, tempArray);
    delete[] resultArray;
    resultArray = tempArray;

    resultArray[newSize - 2] = sum;
    resultArray[newSize - 1] = average;

    return resultArray;
}