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

Задание 2.
1. Опишите класс «Траектория», производный от точки, 
    описывающий некоторую траекторию движения точки по прямой линии: Y=k*x+b.
2. Определите конструктор траектории по умолчанию и с параметрами.
3. Опишите метод, который позволит вывести на экран 
    таблицу значений координат точек, расположенных на траектории. 
    Количество выводимых точек должно быть его параметром.
4. Объявите некоторую траекторию, 
    выведите на экран таблицу значений координат ее точек.
5. Определите операцию сравнения траекторий. 
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
bool show_constructor_events = false;
//вывод значений полей при создании объектов
bool show_constructed_object_description = false;

//точка
class Point
{
protected: //-> Trajectory
    float m_Ox;
    float m_Oy;

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
    Point(float arg_Ox, float arg_Oy) : m_Ox(arg_Ox), m_Oy(arg_Oy)
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
        float x_side_squared = pow(m_Ox, 2);
        float y_side_squared = pow(m_Oy, 2);
        float vector_squared = x_side_squared + y_side_squared;
        float raw_result = sqrt(vector_squared);

        //два знака после запятой
        float rounded_result = (round(raw_result * 100)) / 100;
        return rounded_result;
    }

    //вывод координат
    void showPoint()
    {
        cout << "[X = " << right << setw(3) << m_Ox << "] "
             << "[Y = " << right << setw(3) << m_Oy << "] ";
    }

    float fetch_coordinates(char type)
    {
        if (type == 'x')
        {
            //cout << endl
            //<< "returning X...";
            return m_Ox;
        }
        else if (type == 'y')
        {
            //cout << endl
            //<< "returning Y...";
            return m_Oy;
        }
        else
        {
            cout << endl
                 << "Error at fetch_coordinates(): Wrong argument (char type is either 'x' or 'y').";
            return INT32_MAX;
        }
    }

    //вывод параметров точки в консоль (динамические объекты)
    friend std::ostream &operator<<(std::ostream &cout_stream, Point *ptr_point)
    {
        //здесь - с более эргономичным форматом таблицы
        cout_stream << "  \n  >> "
                    << "[T = DYN] " //динамический
                    << "[X = " << right << setw(6) << ptr_point->m_Ox << "] "
                    << "[Y = " << right << setw(6) << ptr_point->m_Oy << "] "
                    << "[HX = " << right << printf("0x%08x", ptr_point) << "] "          //0х-адрес
                    << "[VCTR = " << right << setw(6) << ptr_point->getVector() << "] "; //длина радиус-вектора

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

////////////////////////////////////////////////////////
//вектор
class Trajectory : public Point
{
private:
    float m_k; //угловой коэфициент
    float m_b; //смещение
public:
    //=======================================================
    //конструктор по умолчанию: от данной точки через начало координат
    Trajectory(Point *ptr_point)
    {
        //первая точка - начало координат
        m_Ox = m_Oy = 0;

        //вторая точка - произвольная
        float x2, y2;
        x2 = ptr_point->fetch_coordinates('x');
        y2 = ptr_point->fetch_coordinates('y');

        //две точки позволяют однозначно определить коэффициент и смещение
        m_k = (y2 - m_Oy) / (x2 - m_Ox);
        m_b = ((x2 * m_Oy) - (y2 * m_Ox)) / (x2 - m_Ox);

        //вывод сообщений
        if (show_constructed_object_description)
            showDescription();
        if (show_constructor_events)
            cout << "[Default Trajectory(Point *ptr_point) have been constructed] ";
    }

    //произвольный конструктор через коэффициент и смещение
    Trajectory(float arg_k, float arg_b)
    {
        m_k = arg_k;
        m_b = arg_b;

        //коэффициент и смещение позволяют однозначно определить точку
        m_Ox = 0;   //траектория определена на всей оси абсцисс
        m_Oy = m_b; //т.к. kx = 0

        //вывод сообщений
        if (show_constructed_object_description)
            showDescription();
        if (show_constructor_events)
            cout << "[Custom Trajectory(float arg_k, float arg_b) have been constructed] ";
    }

    //вывод значений полей при создани объектов (функция)
    void showDescription()
    {
        cout << endl
             << "[TR: "
             << "y"
             << " = " << m_k << "*"
             << "x"
             << " + " << m_b << "] ";
        //поля соовтетствующей точки
        showPoint();
    }

    //сравнение траекторий (по коэффициенту и смещению)
    bool operator==(Trajectory& arg_trajectory_obj)
    {
        bool isEqual, check_k, check_b;
        check_k = this->m_k==arg_trajectory_obj.m_k;
        check_b = this->m_b==arg_trajectory_obj.m_b;
        isEqual = check_k && check_b;
        return isEqual;
    }
    //=======================================================

    //принадлежность точки прямой (траектории) (по указателю на точку)
    bool checkPoint(Point *arg_point_obj)
    {
        float x_coordinate, y_coordinate;
        x_coordinate = arg_point_obj->fetch_coordinates('x');
        y_coordinate = arg_point_obj->fetch_coordinates('y');

        //если соответствует уравнению прямой (траектории)
        if (y_coordinate == m_k * x_coordinate + m_b)
            return true;
        else
            return false;
    }

    //количество точек, принадлежащих прямой
    //аргументы - массив указателей на точки и его размер
    int get_aligned_points_count(Point *arg_arr_point_ptr[], int arg_ptr_array_size)
    {
        int point_count = 0;         //число точек, принадлежащих прямой
        bool isOnTrajectory = false; //принадлежность прямой

        for (int i = 0; i < arg_ptr_array_size; i++)
        {
            isOnTrajectory = checkPoint(arg_arr_point_ptr[i]);
            if (isOnTrajectory)
                point_count++;
        }
        return point_count;
    }

    //копирует указатели arg_arr_point_ptr в заданный массив того же типа
    //аргументы - исходный, размер исходного, целевой, размер целевого
    int copy_aligned_points_pointers(Point *arg_arr_point_ptr[], int arg_ptr_array_size,
                                     Point *arg_arr_point_ptr_aligned[], int arg_ptr_array_aligned_size)
    {
        int point_count = arg_ptr_array_aligned_size; //число точек, принадлежащих прямой
        bool isOnTrajectory = false;                  //принадлежность прямой

        int j; //позиия копирования в массиве
        for (int i = 0; i < arg_ptr_array_size; i++)
        {
            isOnTrajectory = checkPoint(arg_arr_point_ptr[i]);
            if (isOnTrajectory)
                arg_arr_point_ptr_aligned[j++] = arg_arr_point_ptr[i];
        }
        return 1;
    }

    //печать первых N точек, принадлежащих прямой (траектории)
    //для вызова должен существовать ранее созданный массив принадлежащих точек
    void print_aligned_points(int N, Point *arr_point_ptr_aligned[], int arr_point_ptr_aligned_size)
    { //точки берутся из массива указателей на точки
        //если такого количества точек нет - печатаем максимально возможное
        if (arr_point_ptr_aligned_size > 0)
        {
            if (arr_point_ptr_aligned_size < N)
            {
                cout << endl
                     << "ERROR at print_aligned_points(...): Maximum points count is: "
                     << arr_point_ptr_aligned_size;
                N = arr_point_ptr_aligned_size;
            }
            for (int i = 0; i < N; i++)
            {
                cout << arr_point_ptr_aligned[i];
                cout << " [TRUE]";
            }
        }
        else
        {
            cout << endl
                 //в переданном массиве подходящих точек на найдено
                 << "No aligned points found in source array."; 
            return;
        }
    }
};
////////////////////////////////////////////////////////

int main()
{
    //первая часть - массив точек и расчет их радиус-векторов

    //массив укаpателей на объекты-точки (в куче)
    const int ARR_SIZE = 1024*768;
    Point **arr_point_ptr = new Point*[ARR_SIZE];

    //случайные значения координат
    srand(time(0)); //seed
    int random_x;
    int random_y;
    //интервал разброса случайных значений координат
    const int RAND_INTERVAL = 25;

    //получаем память и заполняем координаты случайным значениями
    for (int i = 0; i < ARR_SIZE; i++)
    {
        random_x = (rand() - rand()) % RAND_INTERVAL;
        random_y = (rand() - rand()) % RAND_INTERVAL;
        arr_point_ptr[i] = new Point(random_x, random_y);
    }
    cout << "\n Total number of points is " << ARR_SIZE << ".";

    //вторая часть - работа с траекториями
    show_constructor_events = show_constructed_object_description = true;

    //создаем траектории

    //траектория по умолчанию (от первой точки в массиве, например)
    cout << endl
         << "Selected point for default constructor is on next line: " << arr_point_ptr[0];
    Trajectory t1_default(arr_point_ptr[0]);

    //размер массива указателей на точки, принадлежащие прямой
    int aligned_point_arr_size_default = t1_default.get_aligned_points_count(arr_point_ptr, ARR_SIZE);
    Point *arr_point_ptr_aligned_default[aligned_point_arr_size_default];

    //копируем подходящие указатели в "контейнер"
    t1_default.copy_aligned_points_pointers(arr_point_ptr,
                                            ARR_SIZE,
                                            arr_point_ptr_aligned_default,
                                            aligned_point_arr_size_default);
    
    
    //и выводим на экран (здесб - максимум три точки)
    cout << endl;
    cout << endl;
    cout << "==========START_TEST_DEFAULT_TRAJECTORY============";

        t1_default.print_aligned_points(5,
                                        arr_point_ptr_aligned_default,
                                        aligned_point_arr_size_default);

    cout << endl;
    cout << "==========END_TEST_DEFAULT_TRAJECTORY============";
    cout << endl;


    //траектория произвольная(через аргменты k, b)
    Trajectory t2_custom(5, 4);
    //размер массива указателей на точки, принадлежащие прямой
    int aligned_point_arr_size_custom = t2_custom.get_aligned_points_count(arr_point_ptr, ARR_SIZE);
    Point *arr_point_ptr_aligned_custom[aligned_point_arr_size_custom];

    //копируем подходящие указатели в "контейнер"
    t2_custom.copy_aligned_points_pointers(arr_point_ptr,
                                           ARR_SIZE,
                                           arr_point_ptr_aligned_custom,
                                           aligned_point_arr_size_custom);
    
    
    //и выводим на экран (здесб - максимум три точки)
    cout << endl;
    cout << endl;
    cout << "==========START_TEST_CUSTOM_TRAJECTORY============";

        t2_custom.print_aligned_points(5, arr_point_ptr_aligned_custom, aligned_point_arr_size_custom);

    cout << endl;
    cout << "==========END_TEST_CUSTOM_TRAJECTORY============";
    cout << endl;


    Trajectory t3_custom(5, 4), t4_custom(6, 7);
    cout << endl;
    cout << endl;
    cout << "==========START_TEST_OPERATOR \"==\"============";

        t2_custom.showDescription();
        t3_custom.showDescription();
        t4_custom.showDescription();

        cout << endl;
        cout << "t2_custom == t3_custom? : ";
        cout << ((t2_custom == t3_custom) ? "[TRUE]" : "[FALSE]");
        cout << endl;
        cout << "t3_custom == t4_custom? : ";
        cout << ((t3_custom == t4_custom) ? "[TRUE]" : "[FALSE]");

    cout << endl;
    cout << "==========END_TEST_OPERATOR \"==\"============";
    cout << endl;

    sys_pause();
}