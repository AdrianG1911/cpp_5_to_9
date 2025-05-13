#include <iostream>
#include "iter.hpp"

template <typename ting>
void print_ting(const ting& thing)
{
    std::cout << thing << "\n";
}

template <typename ting>
void mulitply_two(ting& thing)
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
    ::iter(arrptr, 5, print_ting<int>);
    std::cout << "long array: \n";
    ::iter(arr2ptr, 5, print_ting<long>);
    ::iter(arrptr, 5, mulitply_two<int>);
    ::iter(arr2ptr, 5, mulitply_two<long>);
    std::cout << "int array after multiply_two: \n";
    ::iter(arrptr, 5, print_ting<int>);
    std::cout << "long array after multiply_two: \n";
    ::iter(arr2ptr, 5, print_ting<long>);
    std::cout << "char array でテストしてみよう！\n";
    ::iter("Hello World", 11, print_ting<char>);
    delete arr2ptr;
}