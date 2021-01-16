/*
Упражнение4.Описание функции
Пусть требуется вычислить функцию Y(x) = A∙Sin(φ∙x).
Напишите новую функцию Table_А, так, 
чтобы ее описание соответствовало новому условию.
Обратитесь в цикле со значениями параметра А= 1,1.5,2.,2.5.
*/


#include "Function.h" //из "Практических_заданий"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    cout // форматируем значения...
    << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::right) // неслетающий флаг...
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2); //знаков после запятой...

    const double pi = 3.14159265359;

    cout << "Initiasing Table()..."; // см. упражнение 3
    cout << "\n";
    Table (0.0, pi, 12.0);
    cout << "Done! [Table()]\n"; //готово

    cout << "===========================================";
    cout << "\n";
    cout << "Initiasing Table_A()..."; // см. упражнение 4
    cout << "\n";

    for ( double i = 1.0; i <= 2.5; i += 0.5 )
    {
        cout << "if i = " << i; //готово
        cout << "\n";
        cout << "===========================================";
        cout << "\n";

        Table_A (0.0, pi, 12, i, 0.6 );

        cout << "Done![Table_A()] for i =" << i; //готово
        cout << "\n";
    }
}