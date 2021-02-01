
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float volume = 0; //объем V

    float height; //высота H
    float max_height = 5; //максимум H
    float min_height = -1 ; //минимум H
    float d_height = 1; //шаг изменения H

    float diameter; //диаметр d
    float max_diameter = 3.5; //максимум d
    float min_diameter = 0.5; //минимум d
    float d_diameter = 0.5; //шаг изменения d

    const float pi = 3.1415926535F; //константа П

        cout // форматируем значения...
    << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::right) // неслетающий флаг...
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2); //знаков после запятой...

    cout << "volume\t"; 
    cout << " height\t"; 
    cout << " diameter\t\n";

    for (diameter = min_diameter; diameter <= max_diameter; diameter += d_diameter)
    {
        
        cout << "~~~~ " << "diameter = " << diameter << " ~~~~" << "\n";

        for (height = min_height; height <= max_height; height += d_height)
        {
            volume = height*pi*(diameter/2)*(diameter/2);
            cout << setw(6) << setfill(' ') << volume << "\t";
            cout << setw(6) << setfill(' ') << height << "\t";
            cout << setw(6) << setfill(' ') << diameter << "\t";
            cout << "\n";
        }
    }
}
