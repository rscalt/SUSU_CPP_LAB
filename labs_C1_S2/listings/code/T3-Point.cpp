/* 
Практическое задание No3: прямое наследование.
Задание 1.
1.Опишите класс «Точка» на координатной плоскости.
    Данные класса: 
        координаты точки в декартовом пространстве.
    Конструкторы класса: 
        конструктор по умолчанию (начало координат), 
        конструктор произвольной точки.
2.Определите методы: 
        ввод-вывод в поток, 
        определение радиуса вектора точки.
3.Объявите объекты с использованием различных конструкторов, 
        найдите их радиусы векторы.
 */

#include <iostream> //cin/cout и стримы
#include <iomanip>  //reserved
#include <cstdlib>  //для rand()
using namespace std;

//system("pause") с новой строки
void sys_pause()
{
    cout << endl;
    system("pause");
}

////////////////////////////////////////////////////////
//вывод сообщений о создании объектов
bool show_constructor_events = true;
//вывод значений полей при создании объектов
bool show_constructed_object_description = true;

//точка
class Point
{
private:
    int m_Ox;
    int m_Oy;

public:
    //конструктор по умолчанию
    Point() : m_Ox(0), m_Oy(0)
    {
        if (show_constructor_events)
        {
            cout << this;
            cout << " [Point() have been constructed]";
        }
    }

    //конструктор произвольной точки
    Point(int arg_Ox, int arg_Oy) : m_Ox(arg_Ox), m_Oy(arg_Oy)
    {
        if (show_constructor_events)
        {
            cout << this;
            cout << " [Point(arg1, arg2) have been constructed]";
        }
    }
    ~Point()
    {
        if (show_constructor_events)
        {
            cout << this;
            cout << " [~Point() have been destroyed ]";
        }
    };

    //вывод параметров точки в консоль (динамические объекты)
    friend std::ostream &operator<<(std::ostream &cout_stream, const Point *ptr_point)
    {
        cout_stream << "  \n  >> "
                    << "[T = DYN] "
                    << "[X = " << ptr_point->m_Ox << "] "
                    << "[Y = " << ptr_point->m_Oy << "] "
                    << "[HX: " << printf("0x%08x", ptr_point) << "]";
        return cout_stream;
    }

    //ввод параметров точки из консоли (динамические объекты)
    friend std::istream &operator>>(std::istream &cin_stream, Point *ptr_point)
    {
        cin_stream >> ptr_point->m_Ox >> ptr_point->m_Oy;
        return cin_stream;
    }
};
////////////////////////////////////////////////////////

int main()
{
    //массив укаpателей на объекты-точки;
    const int ARR_SIZE = 5;
    Point *arr_point_ptr[ARR_SIZE];

    //случайные значения координат и интервал разброса
    int random_x;
    int random_y;
    const int RAND_INTERVAL = 10;

    //получаем память и заполняем координаты случайным значениями
    for (int i = 0; i < ARR_SIZE; i++)
    {
        random_x = (rand() - rand()) % RAND_INTERVAL;
        random_y = (rand() - rand()) % RAND_INTERVAL;

        arr_point_ptr[i] = new Point(random_x, random_y);
    }
    cout << "\n Total number of points is " << ARR_SIZE << ".";

    //можно изменить коордиаты точек (все разом)
    bool confirm_edit_coordinates = 0;
    cout << "\n Edit points coordinates? (1 = yes / 0 = no): ";
    cin >> confirm_edit_coordinates;

    if (confirm_edit_coordinates)
    {
        cout << "\n Edit constructed points coordinates (as pairs of numbers): ";
        for (int j = 0; j < ARR_SIZE; j++)
            cin >> arr_point_ptr[j];
    }

    //результат ввода
    cout << "Printing points...";
    for (int k = 0; k < ARR_SIZE; k++)
        cout << arr_point_ptr[k];

    
}