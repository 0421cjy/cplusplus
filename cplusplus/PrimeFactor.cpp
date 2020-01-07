#include "PrimeFactor.h"

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
