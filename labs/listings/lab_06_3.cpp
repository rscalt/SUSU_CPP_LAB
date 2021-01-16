#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

int main()
{
    cout << setw(20) << "Basic: "; //исходный
    print();

    cout << setw(20) << "Overload for 10: "; // первый
    print(10);
    cout << setw(20) << "Overload for 5: "; //второй    
    print(5);
    cout << setw(20) << "Overload for 1: "; // третий
    print(1);

    print(110);

    cout << setw(30) << "Overload for 10 and '$' : "; // первый
    print(10, '$');
    cout << setw(30) << "Overload for 5 and '%' : "; //второй    
    print(5, '%');
    cout << setw(30) << "Overload for 90 and '=' : "; // третий
    print(90, '=');
    
}