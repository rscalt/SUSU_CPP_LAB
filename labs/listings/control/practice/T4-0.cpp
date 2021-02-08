/* 
Вычислить значение полинома P(x)в произвольной точке x, (...)
Выполнить вычисления для 100 слагаемых. 
Во внешнем цикле составить таблицу, 
выводящую на экран значение полинома для х e[–0.5; 1,1].
 */

#include <iostream>
#include <iomanip>
 //без <math.h>
using namespace std;

int main()
{
    cout << setiosflags(ios::fixed) // неслетающий флаг...
    << setiosflags(ios::showpoint) // всегда с точкой...
    << setprecision(2); //знаков после запятой...

    float x0 = 1.0F; //первое слагаемое
    float x_current; //заданная точка

    int n_max = 100; // общее количество слагаемых

    float min_x = -0.5;
    float max_x = 1.1;
    float delta_x = 0.1; //шаг x
    float offset = delta_x/100; //правка на "двоичную" погрешность  
 

    cout << "x \t" << "P(x) \t" << endl; //шапка таблицы
    for (float x_current = min_x ; x_current <= max_x+offset ; x_current+=delta_x)
        { //при каждом входе в цикл... [с разным значением]

        float x_n = 0; //причесываем значения
        float x_old = x0;
        float x_new = x_current;
        float total_sum = x0; //1
        
        for (int n = 1; n <= n_max-1; n++) //нулевое слагаемое (x0==1) уже есть
            { 
            x_n = x_old*x_new; //новое слагаемое == предыдущее*x_current
            total_sum += x_n; //сохраняем результат
            x_old = x_n; //
            }
        cout << x_current << "\t" << total_sum << "\n";

        }

}
