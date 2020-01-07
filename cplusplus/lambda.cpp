#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <algorithm>

template <typename T>
void fill(std::vector<int>& vec, T done)
{
    int i = 0;

    while (!done())
    {
        vec.push_back(i++);
    }
}

class gorp
{
    std::vector<int> values;
    int m;

public:
    gorp(int mod) : m(mod) {}
    gorp& put(int v)
    {
        values.push_back(v);
        return *this;
    }

    int extras()
    {
        int count = 0;
        for_each(values.begin(), values.end(), [=, &count](int v) {count += v % m; });
        return count;
    }
};

int main()
{
    std::function<int(int)> factioral = [&](int number)
    {
        return number > 1 ? number *= factioral(number - 1) : 1;
    };

    std::cout << factioral(5) << std::endl;

    std::vector<int> stuff;
    fill(stuff, [&]() { return stuff.size() >= 8; });

    for_each(stuff.begin(), stuff.end(), [&](int i) { std::cout << i << " "; });

    gorp g(4);
    g.put(3).put(7).put(8);

    std::cout << "extras: " << g.extras();

    std::function<int(int)> fact;

    fact = [&fact](int number) -> int {
        if (number == 0)
        {
            return 1;
        }
        else
        {
            return (number *= fact(number - 1));
        }
    };

    std::cout << "factorial" << fact(4) << std::endl;

    int in;
    std::cin >> in;
}
