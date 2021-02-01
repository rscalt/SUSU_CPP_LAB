#include <math.h>
#include <iostream>

int main()
{
    const double PI = 3.14159265;
    double sin_result;

    int k; //заданный k
    std::cout << "Enter k: \n";
    std::cin >> k;

    int counter = 0; //счетчик положительных

    for (int i = 0; i < k; i++)
        {
        sin_result = sin(i*(PI/180)); //sin(double radians)
        if (sin_result < 0) 
            std::cout << "#" << i << std::endl;
        else if (sin_result > 0) 
            counter++;
        else continue;
        }
    std::cout << "Counter is " << counter << std::endl;
}