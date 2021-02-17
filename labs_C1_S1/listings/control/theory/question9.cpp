#include <math.h>
#include <iostream>

int main()
{
    float x, y;
    std::cout << "Enter x and y: \n";
    std::cin >> x;
    std::cin >> y;
    if (abs(x)<= 1 && abs(y) <= 1) //ограничение предметной области квадратом 2*2 с центром в начале координат
    { //график симметричен относительно оси абсцисс - x можно брать по модулю
        if  (y == 0)
            {
            if ( abs(x) <= 1 ) //по точкам пересечения -0ЗЩЩфигуры с осью абсцисс
            std::cout << "yes";
            return true;
            }
        if ( y > 0 )
            {
            if (abs(x)*y <=1) //площадь верхней части фигуры = 1
            std::cout << "yes";
            return true;
            }
        if ( y < 0 )
            {
            if (abs(x)*y <=1/2) //площадь верхней части фигуры = 0,5
            std::cout << "yes";
            return true;
            }
    }
    else 
    {
        std::cout << "no";
        return false;
    }
}