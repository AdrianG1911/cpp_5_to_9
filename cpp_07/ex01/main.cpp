#include <iostream>
#include "iter.hpp"

template <typename T>
void printTing(const T& thing)
{
    std::cout << thing << "\n";
}

template <typename T>
void multiplyTwo(T& thing)
{
    thing *= 2;
}


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *arrptr = arr;
    long *arr2ptr = new long[5];
    for (long i = 0; i < 5; ++i)
        arr2ptr[i] += i + 6;
    std::cout << "int array: \n";
    ::iter(arrptr, 5, printTing<int>);
    std::cout << "long array: \n";
    ::iter(arr2ptr, 5, printTing<long>);
    ::iter(arrptr, 5, multiplyTwo<int>);
    ::iter(arr2ptr, 5, multiplyTwo<long>);
    std::cout << "int array after multiply_two: \n";
    ::iter(arrptr, 5, printTing<int>);
    std::cout << "long array after multiply_two: \n";
    ::iter(arr2ptr, 5, printTing<long>);
    std::cout << "char array でテストしてみよう！\n";
    ::iter("Hello World", 11, printTing<char>);
    delete arr2ptr;
}