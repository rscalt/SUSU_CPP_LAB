/* 
    Практическоезадание No2: перегруженные операции. 
    1.Опишите класс «Кольцо» на координатной плоскости.
    Данные класса:координаты центра кольца и радиусы.
    Конструкторы класса:конструктор по умолчанию, конструктор кольца с центром в начале координат, 
    и конструктор произвольного кольца. 
    Определите методы вычисления площади кольца, принадлежности кольцу точки с указанными координатами.
    2.Для ввода и вывода объектов перегрузите операции >> ввода и << вывода в поток. 
    3.Перегрузите операцию сложения колец с использованием метода класса, а операцию вычитания с использованием дружественной функции.
    4.Перегрузите унарную операцию ++ для инкремента кольца как метод класса,a –– как дружественную функцию.
    5.Перегрузите операцию присваивания для колец.
    6.Перегрузите операцию сравнения == для колец: идентичность значений полей
    7.Перегрузите операцию сравнения > для колец: по значению площади.
    8.Проверьте работу всех операций на статических идинамических объектах 
*/

#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;
////////////////////////////////////////////////////////
class Ring
{
private:
    int m_center_x = 0;
    int m_center_y = 0;

    unsigned int m_outer_radius = 2; //радиус внешнего кольца
    unsigned int m_inner_radius = 1; //радиус внутреннего кольца

    const float m_PI = 3.14159265359;

public:
    //конструкторы
    //===//===//===//===//===//===//===//===//===//===
    //конструктор по умолчанию
    Ring();

    //конструктор с центром в начале координат
    Ring(unsigned int out_rad,
         unsigned int inn_rad);

    //конструктор произвольного кольца
    Ring(unsigned int out_rad,
         unsigned int inn_rad,
         int x_coord,
         int y_coord);

    //деструктор
    ~Ring(){};
    //===//===//===//===//===//===//===//===//===//===

    //################################################
    //методы
    //площадь кольца
    int getArea()
    {
        int area;
        area = m_PI * (m_outer_radius * m_outer_radius - m_inner_radius * m_inner_radius);
        return area;
    }

    //принадлежность кольцу точки с указанными координатами
    bool is_point_inside(int point_x, int point_y)
    {
        int dist_total, dist_x, dist_y;
        dist_x = pow((point_x - m_center_x), 2);
        dist_y = pow((point_y - m_center_y), 2);
        dist_total = sqrt(dist_x + dist_y);

        if (dist_total >= m_inner_radius && dist_total <= m_outer_radius)
            return true;
        else
            return false;
    }

    //вывод параметров кольца в консоль
    friend std::ostream &operator<<(std::ostream &cout_stream, const Ring &ring_object)
    {
        cout_stream << "\nThe Ring parameters are: \n"
                    << "x0: " << ring_object.m_center_x << "\n"
                    << "y0: " << ring_object.m_center_y << "\n"
                    << "r: " << ring_object.m_inner_radius << "\n"
                    << "R: " << ring_object.m_outer_radius << "\n";
        return cout_stream;
    }

    //ввод параметров кольца из консоли
    friend std::istream &operator>>(std::istream &cin_stream, Ring &new_ring_object)
    {
        cin_stream >> new_ring_object.m_center_x >> new_ring_object.m_center_y >> new_ring_object.m_inner_radius >> new_ring_object.m_outer_radius;

        return cin_stream;
    }

    //сложение колец через метод класса
    Ring Ring::operator+(Ring &ring_object_right)
    {
        int new_temp_x = this->m_center_x + ring_object_right.m_center_x;
        int new_temp_y = this->m_center_y + ring_object_right.m_center_x;
        int new_inn_rad = this->m_inner_radius + ring_object_right.m_inner_radius;
        int new_out_rad = this->m_outer_radius + ring_object_right.m_outer_radius;

        Ring new_ring(new_temp_x, new_temp_y, new_inn_rad, new_out_rad);
        return new_ring;
    }

    //вычитание колец через дружественную функцию
    friend Ring operator-(Ring &ring_object_left, Ring &ring_object_right)
    {
        int new_temp_x = ring_object_left.m_center_x - ring_object_right.m_center_x;
        int new_temp_y = ring_object_left.m_center_y - ring_object_right.m_center_x;
        int new_inn_rad = ring_object_left.m_inner_radius - ring_object_right.m_inner_radius;
        int new_out_rad = ring_object_left.m_outer_radius - ring_object_right.m_outer_radius;

        Ring new_ring(new_temp_x, new_temp_y, new_inn_rad, new_out_rad);
        return new_ring; 
    }

    //################################################

    //++++++++++++++++++++++++++++++++++++++++++++++++

    //++++++++++++++++++++++++++++++++++++++++++++++++
};
//===//===//===//===//===//===//===//===//===//===
Ring::Ring() : m_center_x(0),
               m_center_y(0),
               m_inner_radius(1),
               m_outer_radius(2)
{
    cout << "\nDefault Ring have been created";
}

Ring::Ring(unsigned int inn_rad,
           unsigned int out_rad) : m_center_x(0),
                                   m_center_y(0),
                                   m_inner_radius(inn_rad),
                                   m_outer_radius(out_rad)
{
    cout << "\nCentered Ring have been created";
    cout << "\nIt`s radiuses are " << out_rad << " and " << inn_rad << "\n";
}

Ring::Ring(unsigned int inn_rad,
           unsigned int out_rad,
           int x_coord,
           int y_coord) : m_center_x(x_coord),
                          m_center_y(y_coord),
                          m_inner_radius(inn_rad),
                          m_outer_radius(out_rad)
{
    cout << "\nCustom Ring have been created";
    cout << "\nIt`s radiuses are " << out_rad << " and " << inn_rad << "\n";
}
//===//===//===//===//===//===//===//===//===//===

int main()
{
    Ring ring1, ring2(10, 20), ring3(11, 22, 1, 1);
    cout << "\nEnter ring parameters: ";
    cin >> ring1;
    cout << ring1;
    cout << ring2;
    cout << ring3;

    cout << "========test1===========";
    cout << ring1+ring2;
    cout << "========test2===========";
    cout << ring3-ring2;
}
