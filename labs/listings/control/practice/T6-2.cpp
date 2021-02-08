#include <iostream>
using namespace std;

float square(float outer_radius, float inner_radius);
const float PI = 3.14159F;

int main()
{   
    float r1, r2, area;
    cout << "Enter outer radius: "; cin >> r1; //внешний
    cout << "Enter inner radius: "; cin >> r2; //внутренний
    area = square(r1, r2);
    cout << "Ring area is " << area << endl; //результат
}


//площадь кольца с заданными радиусами внешней и внутренней окружности
float square (float outer_radius, float inner_radius)
{
    if (outer_radius > inner_radius)
        {
        float outer_square = PI*outer_radius*outer_radius; //площадь по внешней окружности
        float inner_square = PI*inner_radius*inner_radius; //площадь по внутренней окружности
        float ring_square = outer_square - inner_square; //разница == площадь кольца
        return ring_square;
        }
    else
        return 0;
}