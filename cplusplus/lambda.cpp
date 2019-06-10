#include <iostream>
#include <functional>

int main()
{
    std::function<int(int)> factorial = [&factorial](int number) {
        return number > 1 ? number * factorial(number - 1) : 1;
    };

    std::cout << factorial(5) << std::endl;

    int in;
    std::cin >> in;
}