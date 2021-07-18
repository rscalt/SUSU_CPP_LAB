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
#include <math.h>   //для rand()
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

    //деструктор
    ~Point()
    {
        if (show_constructor_events)
        {
            cout << this;
            cout << " [~Point() have been destroyed ]";
        }
    }

    //расчет радиус-вектора точки по координатам
    float getVector()
    {
        int x_side_squared = pow(m_Ox, 2);
        int y_side_squared = pow(m_Oy, 2);
        int vector_squared = x_side_squared + y_side_squared;
        float raw_result = sqrt(vector_squared);

        //два знака после запятой
        float rounded_result = (round(raw_result * 100)) / 100; 
        return rounded_result;
    }

    //вывод параметров точки в консоль (динамические объекты)
    friend std::ostream &operator<<(std::ostream &cout_stream, Point *ptr_point)
    {
        //здесь - с более эргономичным форматом таблицы
        cout_stream << "  \n  >> "
                    << "[T = DYN] " //динамический
                    << "[X = "  << right << setw(3) << ptr_point->m_Ox << "] "
                    << "[Y = "  << right << setw(3) << ptr_point->m_Oy << "] "
                    << "[HX = " << right << printf("0x%08x", ptr_point) << "]" //0х-адрес
            << " [VCTR = " //длина радиус-вектора
            << right  //классическое форматиирование результатов
            << setfill(' ') 
            << setw(6) 
            << setprecision(2) 
            << fixed
            << ptr_point->getVector()
            << "]";

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

//вектор
class Trajectory
{
private:
public:
};

////////////////////////////////////////////////////////

int main()
{
    //массив укаpателей на объекты-точки;
    const int ARR_SIZE = 5;
    Point *arr_point_ptr[ARR_SIZE];

    //случайные значения координат
    srand(time(0)); //seed
    int random_x;
    int random_y;
    //интервал разброса случайных значений координат
    const int RAND_INTERVAL = 10;

    //получаем память и заполняем координаты случайным значениями
    for (int i = 0; i < ARR_SIZE; i++)
    {
        random_x = (rand() - rand()) % RAND_INTERVAL;
        random_y = (rand() - rand()) % RAND_INTERVAL;

        arr_point_ptr[i] = new Point(random_x, random_y);
    }
    cout << "\n Total number of points is " << ARR_SIZE << ".";

    //можно изменить координаты точек (все разом)
    bool confirm_edit_coordinates = false;
    //cout << "\n Edit points coordinates? (1 = yes / 0 = no): ";
    //cin >> confirm_edit_coordinates;
    if (confirm_edit_coordinates)
    {
        cout << "\n Edit constructed points coordinates (as pairs of numbers): ";
        for (int j = 0; j < ARR_SIZE; j++)
            cin >> arr_point_ptr[j];

        //результат ввода
        cout << "\nPrinting points...";
        for (int k = 0; k < ARR_SIZE; k++)
            cout << arr_point_ptr[k];
    }
}