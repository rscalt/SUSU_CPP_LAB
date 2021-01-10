/*  
Упражнение 1. Выбор одной из двух возможных ситуаций
Запишите код программы для решения задачи. 
Ввести координаты точки на плоскости
и определить, находится ли точка с координатами (x, y) в первой или в третьей четверти, 
и не дальше, чем 3 см от начала координат.
Для проверки условия использовать логическое выражение.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    unsigned short x, y; // декартовы координаты точки
    
    cout << "Enter cartesian coordinates for A (x,y): \n"; //декартовы
    cin >> x;
    cin >> y;
    cout << "A(" << x << "," << y << "):\n";

    float l; // для расстояния от начала координат
    l = sqrt(x*x + y*y); //через теорему Пифагора

    cout << "Distance is "<< l << "\n";

    if  ( 
              ( (x > 0 && y > 0) || (x < 0 && y < 0) )
              && (l <= 3)
        ) cout << "QI or QIII, distance <= 3 \n"; 

    else   cout << "Quadrant is II or IV; or distance > 3\n";

    system("pause");
    system("cls");
}
