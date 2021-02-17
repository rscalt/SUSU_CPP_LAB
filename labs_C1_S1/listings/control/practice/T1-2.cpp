/* Дан круг радиуса R.
Найти площадь круга.
Найти площадь сектора круга с указанным значением центрального угла. */

#include <iostream>

int main()
{
    const float PI = 3.14159265359F;
    float R; //радиус
    float angle; // центральный угол
    std::cout << "Enter R:\n ";
    std::cin >> R;
    std::cout << "Enter angle:\n ";
    std::cin >> angle;

    float circle_area = PI*R*R; //площадь круга = pi*r^2...
    float circle_sector = (circle_area/360)*angle; 
    std::cout << "Circle area is "  << circle_area << std::endl;
    std::cout << "Circle sector is "  << circle_sector << std::endl;
}

