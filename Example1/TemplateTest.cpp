#include <iostream>
#include <type_traits>

using namespace std;

class A 
{
public:
    template <typename T, typename = std::enable_if_t<std::is_base_of<A, B>::value>>
    void TestFunc(T parameter)
    {
        return;
    }

    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>, T>>
    void TestFunc2(T parameter)
    {
        return;
    }

    template <typename T, typename = std::enable_if_t<is_floating_point_v<T>, T>>
    void TestFunc3(T parameter)
    {
        return;
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

    a.TestFunc(B());
    a.TestFunc2(2);
    a.TestFunc3(3.6f);
    cout << "test Func4: " << a.TestFunc4(4.0f) << '\n';

    int input;
    std::cin >> input;

    return 0;
}
