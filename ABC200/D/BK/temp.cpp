#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    std::cout << vec.front() << std::endl;
    std::cout << vec.back() << std::endl;

    //値の書き換えもできる
    vec.back() = 50;

    std::cout << vec.back() << std::endl;

    std::cin.get();
}