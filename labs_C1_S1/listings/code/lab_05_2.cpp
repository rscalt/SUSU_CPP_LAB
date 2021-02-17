/*
Упражнение 2.Описание функции и обращение к ней
В заголовочном файле опишите функцию, которая возвращает площадь треугольника по заданным значениям длин сторон. 
Если треугольник не существует, функция возвраща-ет 0.Протестируйте функцию, обратившись к ней трижды, 
со значениями длин сторон (3.,4.,5.), 
затем (1.,1.,3.), затем (4.,4.,4.).
*/

#include <iostream>
#include <math.h>
#include "area_heron.h" //функция в заголовочном файле

using namespace std;
float area_heron(float side_a, float side_b, float side_c); //объявление функции

int main()
{   
     cout // форматируем значения...
    << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::right) // неслетающий флаг...
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2); //знаков после запятой...

    float a, b, c;
    cout << "main() initiated...\n";

    cout << "Enther sides length (a, b, c):\n";
    cin >> a;
    cin >> b;
    cin >> c;
    
    if (a + b > c && a + c > b && b + c > a) //проверка корректности введенных данных
    {
        cout << "Triangle exists.\n" 
        << "Sides length are " 
        << a << ", " << b << ", " << c << "\n"; //треугольник существует

        cout << "Calculating triangle area...\n";

        float area_main = area_heron(a, b, c); //вызов функции
        cout << "Triangle area is " << area_main << "\n"; //результат (площадь)
    }
    else 
        cout << "No such triangle exists!\n"; //если треугольника не существует

    system("pause");
}