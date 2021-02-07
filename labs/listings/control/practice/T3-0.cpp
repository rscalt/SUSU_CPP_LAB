#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    cout 
    << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2) //знаков после запятой...
    << setw(4); //ширина поля;
    
    const float PI = 3.14159265359F;
    
    float max_x = 4.0;
    float min_x = -4.0;
    float delta_x = 0.3;
    float x_offset = delta_x/10; //для компенсации двочиной погрешности float-переменных // magic numbers everyhwere
    float current_x = 0.0;
    //float current_x = 0;

    float max_a = 1.6;
    float min_a = 1.2;
    float delta_a = 0.1;
    float a_offset = delta_a/2; //для компенсации двочиной погрешности float-переменных // magic numbers everyhwere
    float current_a = 0.0;

    float y_x = 0;

    cout << "a" << "\t" << "x" << "\t" << "y(x)" << endl;
    for (current_a = min_a; current_a <= max_a+a_offset; current_a += delta_a)
        {
        cout << "~~~~~ a = " << current_a << " ~~~~~~" << endl;
        for (current_x = min_x; current_x < max_x+x_offset; current_x += delta_x)
            {
            if (current_x < 0)
                {
                y_x = sin(current_x+current_a);
                cout << current_a << "\t" << current_x << "\t" << y_x << endl;
                }
            if (current_x >= 0 && current_x <= 2) 
                {
                y_x = cos(PI*current_x);
                cout << current_a << "\t" << current_x << "\t" << y_x << endl;
                }
            if (current_x > 2) 
                {
                y_x = current_a*current_a + current_x*current_x;
                cout << current_a << "\t" << current_x << "\t" << y_x << endl;
                }
            }
        }
}