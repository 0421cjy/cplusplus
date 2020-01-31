#include "PrimeFactor.h"
#include <cmath>

using namespace std;

MyMathClass::MyMathClass()
{
}

MyMathClass::~MyMathClass()
{
}

void MyMathClass::FindPrimeFactor()
{
    while (true)
    {
        cout << "Find Prime Factor" << endl;
        cout << "Please Insert Number..." << endl;

        int number;
        scanf_s("%d", &number);

        if (number == 0) return;

        for (int i = 2; i < number; i++)
        {
            while (number % i == 0)
            {
                printf("%d ", i);
                number /= i;
            }
        }

        // Except trivial divisor
        if (number > 1) printf("%d \n", number);
    }
}

void MyMathClass::FindPrimeFactor2()
{
    while (true)
    {
        cout << "Find Prime Factor" << endl;
        cout << "Please Insert Number..." << endl;

        int number;
        scanf_s("%d", &number);

        if (number == 0) return;

        FindPrimeFactor(number);
    }
}

void MyMathClass::FindPrimeFactor(int number)
{
    int sqrtNum = static_cast<int>(sqrt(number));

    for (int i = sqrtNum; i < number; i++)
    {
        while (number % i == 0)
        {
            if (i == 1)
            {
                printf("%d ", number);
                break;
            }

            printf("%d ", i);

            auto newNum = number / i;
            FindPrimeFactor(newNum);
        }
    }
}

