#include <iostream>
#include <type_traits>

using namespace std;

class A
{
public:
    template <typename T, typename = std::enable_if_t<std::is_base_of<A, B>::value>>
    T TestFunc(T parameter)
    {
        return parameter;
    }

    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>, T>>
    T TestFunc2(T parameter)
    {
        return parameter;
    }

    template <typename T, typename = std::enable_if_t<is_floating_point_v<T>, T>>
    T TestFunc3(T parameter)
    {
        return parameter;
    }

    template <typename T>
    typename enable_if_t<is_floating_point_v<T>, T>
        TestFunc4(T parameter)
    {
        return parameter + parameter;
    }
};

class B : A {};

class C {};

int main()
{
    cout << std::boolalpha;
    cout << "a2b: " << std::is_base_of<A, B>::value << '\n';
    cout << "b2a: " << std::is_base_of<B, A>::value << '\n';
    cout << "c2b: " << std::is_base_of<C, B>::value << '\n';
    cout << "same type: " << std::is_base_of<C, C>::value << '\n';

    A a;

    //cout << "test Func: " << a.TestFunc(B()) << '\n';
    cout << "test Func2: " << a.TestFunc2(2) << '\n';
    cout << "test Func3: " << a.TestFunc3(3.6f) << '\n';
    cout << "test Func4: " << a.TestFunc4(4.0f) << '\n';

    int input;
    std::cin >> input;

    return 0;
}
