#include <iostream>

using namespace std;

void FindPrimeFactor()
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
                number /= i;
                printf_s("%d ", i);
            }
        }

        printf("\n");
        printf("---------------------------------------------------------");
        printf("\n");
    }
}
