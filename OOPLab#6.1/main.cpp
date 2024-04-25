#include "CustomArray.h"
#include <iostream>
#include <ctime>

int main() {
    const CustomArray::size_type size = 5;
    CustomArray::value_type initialArray[size]{};

    srand(time(0));
    for (CustomArray::size_type i = 0; i < size; ++i) {
        initialArray[i] = rand() % 101 - 50;
    }

    CustomArray::size_type newSize = 0;
    CustomArray customArray;
    CustomArray::value_type* resultArray = customArray.processArray(initialArray, size, newSize);

    std::cout << "Result Array: ";
    for (CustomArray::size_type i = 0; i < newSize; ++i) {
        std::cout << resultArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] resultArray;

    return 0;
}
