#include <iostream>
#include <vector>
#include <string>

using namespace std;

class testClass
{
public:
    testClass()
    {
        std::cout << "call constructor!!" << std::endl;
    }

    testClass(int num, std::string name)
        : m_number(num), m_name(name)
    {
        std::cout << "call constrtuctor with parameter" << std::endl;
    }

    testClass(testClass& tc)
    {
        std::cout << "call copy constructor!!" << std::endl;
    }

    testClass(testClass&& tc)
    {
        std::cout << "call move constructor!!" << std::endl;
    }

    ~testClass()
    {
        std::cout << "destructor!!" << std::endl;
    }

private:
    int m_number;
    std::string m_name;
};

int main()
{
    std::vector<testClass> tcVec;

    tcVec.push_back(testClass(1, "test"));
    //tcVec.push_back(2, "test");
    tcVec.emplace_back(testClass(3, "test"));
    tcVec.emplace_back(4, "test");

    return EXIT_SUCCESS;
}