#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

float area_heron(float A, float B, float C) //площадь треугольника по формуле Герона
{   
         cout // форматируем значения...
    << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::right) // неслетающий флаг...
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2); //знаков после запятой...

    cout << "\tarea_heron() initiated...\n";
    float s = (A+B+C)/2; //полупериметр
    cout << "\ts = " << s << "\n";

    float area2 = s*(s-A)*(s-B)*(s-C); //квадрат площади
    if (area2 > 0)
        { 
        cout << "\tArea^2 = " << area2 << "\n";
        float area = sqrt(area2);
        cout << "\tArea = " << area << "\n";
        cout << "\tarea_heron() finished successfully!\n";
        return area;
        }
    else 
        {
        cout << "\tarea_heron() finished with error. \n \t" <<
        "(Please, check the sides!) \n";
        return 0;
        }
}