#include <iostream>
#include "Array.hpp"
#include <time.h>
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        if (i < 10)
            std::cout << numbers[i] << "\n";
    }
    delete [] mirror;//
    Array<Array< int > > complex(5);
    for (int i = 0; i < 5; ++i)
    {
        Array<int> inner(5);
        complex[i] = inner;
        complex[i][0] = i + 100;
    }
    std::cout << complex[3][0] << "\n";
    Array<int> empty;
    empty = complex[1];
    std::cout << empty[0] << "\n";

    Array<int> arrr(5);
    for (int i = 0; i < 5; i++)
        std::cout << arrr[i] << std::endl;
    Array<int> copytest(4);
    for (size_t i = 0; i < 4; i++)
        copytest[i] = i;
    std::cout << "copytest" << std::endl;
    for (size_t i = 0; i < 4; i++)
        std::cout << " " << copytest[i]; 
    std::cout << std::endl;
    Array<int> ct2(copytest);
    std::cout << "ct2" << std::endl;
    for (size_t i = 0; i < 4; i++)
        std::cout << " " << ct2[i]; 
    std::cout << std::endl;
    Array<int> ct3(10);
    ct3 = copytest;
    std::cout << "ct3" << std::endl;
    for (size_t i = 0; i < 4; i++)
        std::cout << " " << ct3[i]; 
    std::cout << std::endl;
    copytest[1] = 9;
    std::cout << "copytest" << std::endl;
    for (size_t i = 0; i < 4; i++)
        std::cout << " " << copytest[i]; 
    std::cout << std::endl;
    std::cout << "ct2" << std::endl;
    for (size_t i = 0; i < 4; i++)
        std::cout << " " << ct2[i]; 
    std::cout << std::endl;
    std::cout << "ct3" << std::endl;
    for (size_t i = 0; i < 4; i++)
        std::cout << " " << ct3[i]; 
    std::cout << std::endl;
    return 0;
}