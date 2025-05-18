#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>


int main() {
    // --- std::vector ---
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(3);

    std::cout << "Searching for 3 in vector: " << easyfind(vec, 3) << std::endl;
    std::cout << "Searching for 100 in vector: " << easyfind(vec, 100) << std::endl;

    std::vector<int> empty_vec;
    std::cout << "Searching for 10 in empty vector: " << easyfind(empty_vec, 10) << std::endl;


    // --- std::list ---
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(15);
    lst.push_back(35);

    std::cout << "Searching for 35 in list: " << easyfind(lst, 35) << std::endl;


    // --- std::deque ---
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    std::cout << "Searching for 200 in deque: " << easyfind(deq, 200) << std::endl;

    return 0;
}