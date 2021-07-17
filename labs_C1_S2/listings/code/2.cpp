/* 
    Практическоезадание No2: перегруженные операции. 
    1.Опишите класс «Кольцо» на координатной плоскости.
    Данные класса:координаты центра кольца и радиусы.
    Конструкторы класса:конструктор по умолчанию, конструктор кольца с центром в начале координат, 
    и конструктор произвольного кольца. 
    Определите методы вычисления площади кольца, принадлежности кольцу точки с указанными координатами.
    2.Для ввода и вывода объектов перегрузите операции >> ввода и << вывода в поток. 
    3.Перегрузите операцию сложения колец с использованием метода класса, а операцию вычитания с использованием дружественной функции.
    4.Перегрузите унарную операцию ++ для инкремента кольца как метод класса, a –– как дружественную функцию.
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

//вывод сообщений о создании объектов
bool show_constructor_events = true;
//вывод значений полей при создании объектов
bool show_constructed_object_description = true;

class Ring
{
private:
    int m_center_x = 0;
    int m_center_y = 0;

    unsigned int m_outer_radius = 0; //радиус внешнего кольца
    unsigned int m_inner_radius = 0; //радиус внутреннего кольца

    const float m_PI = 3.14159265359;

public:
    //конструктор по умолчанию
    Ring();

    //конструктор с центром в начале координат
    Ring(unsigned int inn_rad, unsigned int out_rad);

    //конструктор произвольного кольца
    Ring(unsigned int inn_rad,
         unsigned int out_rad,
         int x_coord,
         int y_coord);

    //деструктор
    ~Ring(){};

    //методы
    //################################################

    //отобразить параметры
    void showDescription() const
    {
        cout << "\n  It`s radiuses are "
             << m_inner_radius << " and " << m_outer_radius << "\n";
        cout << "  Its coordinates are "
             << "( "
             << m_center_x << " , " << m_center_y
             << " )";
    }

    //площадь кольца
    float getArea() const
    {
        float area;
        area = m_PI * (m_outer_radius * m_outer_radius - m_inner_radius * m_inner_radius);
        return area;
    }

    //принадлежность кольцу точки с указанными координатами
    bool isPointInside(int point_x, int point_y) const
    {
        int dist_total, dist_x, dist_y;
        dist_x = pow((point_x - m_center_x), 2);
        dist_y = pow((point_y - m_center_y), 2);
        dist_total = sqrt(dist_x + dist_y);

        bool isInside = (dist_total >= m_inner_radius && dist_total <= m_outer_radius);
        return isInside;
    }

    //вывод параметров кольца в консоль (статические объекты)
    friend std::ostream &operator<<(std::ostream &cout_stream, const Ring &ring_object)
    {
        cout_stream << "  \n  ->Sending parameters to ostream... \n"
                    << "[T = "
                    << "static "
                    << "] "
                    << "[r = " << ring_object.m_inner_radius << "] "
                    << "[R = " << ring_object.m_outer_radius << "] "
                    << "[X = " << ring_object.m_center_x << "] "
                    << "[Y = " << ring_object.m_center_y << "] ";
        return cout_stream;
    }

    //вывод параметров кольца в консоль (динамические объекты)
    friend std::ostream &operator<<(std::ostream &cout_stream, const Ring *ptr_ring_object)
    {
        cout_stream << "  \n  ->Sending parameters to ostream... \n"
                    << "[T = "
                    << "dynamic"
                    << "] "
                    << "[r = " << ptr_ring_object->m_inner_radius << "] "
                    << "[R = " << ptr_ring_object->m_outer_radius << "] "
                    << "[X = " << ptr_ring_object->m_center_x << "] "
                    << "[Y = " << ptr_ring_object->m_center_y << "] ";
        return cout_stream;
    }

    //ввод параметров кольца из консоли (статические объекты)
    friend std::istream &operator>>(std::istream &cin_stream, Ring &new_ring_object)
    {
        cin_stream >> new_ring_object.m_inner_radius >> new_ring_object.m_outer_radius >> new_ring_object.m_center_x >> new_ring_object.m_center_y;

        return cin_stream;
    }

    //ввод параметров кольца из консоли (динамические объекты)
    friend std::istream &operator>>(std::istream &cin_stream, Ring *new_ring_object)
    {
        cin_stream >> new_ring_object->m_inner_radius >> new_ring_object->m_outer_radius >> new_ring_object->m_center_x >> new_ring_object->m_center_y;

        return cin_stream;
    }

    //сложение колец через метод класса
    Ring &operator+(Ring &ring_object_right)
    {
        //сумма центров колец как сумма векторов
        m_inner_radius += ring_object_right.m_inner_radius;
        m_outer_radius += ring_object_right.m_outer_radius;

        m_center_x += ring_object_right.m_center_x;
        m_center_y += ring_object_right.m_center_y;

        return *this;
    }

    //увеличение кольца как метод класса
    //(префикс)
    Ring &operator++()
    {
        m_inner_radius++;
        m_outer_radius++;
        return *this;
    };

    //(постфикс)
    Ring &operator++(int)
    {
        m_inner_radius++;
        m_outer_radius++;
        return *this;
    };
    //вычитание колец через дружественную функцию
    friend Ring operator-(Ring &ring_object_left, Ring &ring_object_right)
    {
        int new_inn_rad = ring_object_left.m_inner_radius - ring_object_right.m_inner_radius;
        int new_out_rad = ring_object_left.m_outer_radius - ring_object_right.m_outer_radius;

        int new_temp_x = ring_object_left.m_center_x - ring_object_right.m_center_x;
        int new_temp_y = ring_object_left.m_center_y - ring_object_right.m_center_y;

        Ring new_ring(new_inn_rad, new_out_rad, new_temp_x, new_temp_y);
        return new_ring;
    }

    //уменьшение кольца как дружественная функция (префикс)
    friend Ring operator--(Ring &ring_object)
    {
        --ring_object.m_inner_radius;
        --ring_object.m_outer_radius;
        return Ring(ring_object.m_inner_radius, ring_object.m_outer_radius);
    }

    //сравнение колец (>) : по площади
    bool operator>(Ring &ring_object_right) const
    {
        cout << "\n  Left Ring area is " << this->getArea();
        cout << "\n  Right Ring area is " << ring_object_right.getArea();

        bool leftIsBigger = (this->getArea() > ring_object_right.getArea());
        return leftIsBigger;
    }

    //сравнение колец (<) : по площади
    bool operator<(Ring &ring_object_right) const
    {
        bool leftIsLower = (this->getArea() < ring_object_right.getArea());
        return leftIsLower;
    }

    //сравнение колец (==) : по идентичности значений полей
    bool operator==(Ring &ring_object_right) const
    {
        bool check_inner_rad = (this->m_inner_radius == ring_object_right.m_inner_radius);
        bool check_outer_rad = (this->m_outer_radius == ring_object_right.m_outer_radius);
        bool check_Ox = (this->m_center_x == ring_object_right.m_center_x);
        bool check_Oy = (this->m_center_y == ring_object_right.m_center_y);

        bool isEqual = (check_inner_rad && check_outer_rad && check_Ox && check_Oy);
        return isEqual;
    }

    //Присваивание колец
    Ring operator=(const Ring &ring_object_right)
    {
        //"this->" избыточен (т.к. неявно подразумевается), но более нагляден
        this->m_inner_radius = ring_object_right.m_inner_radius;
        this->m_outer_radius = ring_object_right.m_outer_radius;
        this->m_center_x = ring_object_right.m_center_x;
        this->m_center_y = ring_object_right.m_center_y;
        return Ring(m_inner_radius, m_outer_radius, m_center_x, m_center_y);
    }

    //################################################
};

//определение конструкторов
//===//===//===//===//===//===//===//===//===//===

Ring::Ring() : m_center_x(3),
               m_center_y(3),
               m_inner_radius(6),
               m_outer_radius(9)
{

    if (show_constructor_events)
    {
        cout << "\nDefault Ring have been created";
        if (show_constructed_object_description)
            showDescription();
    }
}

Ring::Ring(unsigned int inn_rad,
           unsigned int out_rad) : m_inner_radius(inn_rad),
                                   m_outer_radius(out_rad),
                                   m_center_x(0),
                                   m_center_y(0)
{

    if (show_constructor_events)
    {
        cout << "\nCentered Ring have been created";
        if (show_constructed_object_description)
            showDescription();
    }
}

Ring::Ring(unsigned int inn_rad,
           unsigned int out_rad,
           int x_coord,
           int y_coord) : m_inner_radius(inn_rad),
                          m_outer_radius(out_rad),
                          m_center_x(x_coord),
                          m_center_y(y_coord)
{
    if (show_constructor_events)
    {
        cout << "\nCustom Ring have been created";
        if (show_constructed_object_description)
            showDescription();
    }
}
//===//===//===//===//===//===//===//===//===//===

//основной поток
int main()
{
    system("cls");
    show_constructor_events = true;
    show_constructed_object_description = false;
    system("pause");

    show_constructor_events ?
        cout << "\n  Constructor event logging disabled." :
        cout << "\n  Constructor event logging enbaled.";

    show_constructed_object_description ?
        cout << "\n  Constructor event logging disabled." :
        cout << "\n  Constructor event logging enbaled.";

    cout << "\n ==== Testing constructors (static objects) ==== ";
    Ring ring0, ring1, ring2(10, 20), ring3(11, 22, 33, 44);

    cout << endl;
    system("pause");



    cout << "\n ====== Testing ++ and -- operators overload ====== ";
        cout << "\n  Enter new ring parameters: ";
        cin >> ring0;
        cout << ring0;

        cout << "\n  Increasing the ring...";
        ++ring0;
        cout << "\n  Increasing the ring...";
        ++ring0;
        cout << ring0;

        cout << "\n  Decreasing the ring...";
        --ring0;
        cout << ring0;

        cout << endl;
        system("pause");



    cout << "\n ======= Testing (ring 1 + ring 2): ===========";
        cout << ring1 << ring2;

        cout << "\n  Summing rings...";
        cout << (ring1 + ring2);

        cout << endl;
        system("pause");



    cout << "\n ======== Testing (ring 3 - ring 2) :===========";
        cout << ring3;
        cout << ring2;
        cout << "\n  Substracting rings...";
        cout << (ring3 - ring2); 

        cout << endl;
        system("pause");



    cout << "\n ======== Testing > and < operators overload :===========";
        cout << ring0 << ring2;

        cout << "\n  Comparing Rings... (>)";
        ring0 > ring2 ? 
            cout << "\n  [TRUE] ring0 > ring2"  : 
            cout << "\n  [FALSE] ring0 < ring2";

        cout << "\n  Comparing Rings...(<)";
        ring0 < ring2 ? 
            cout << "\n  [TRUE] ring0 < ring2"  : 
            cout << "\n  [FALSE] ring0 > ring2";

    cout << endl;
    system("pause");
 

    cout << "\n ======== Testing \"==\" operator overload :===========";
        cout << ring0 << ring1 << ring2;

        cout << "\n  Checking if rings are identical (ring0 == ring1)...";
        ring0 == ring1 ? 
            cout << "\n  [TRUE] ring0 == ring1" : 
            cout << "\n  [FALSE] ring0 =/= ring1";

        cout << "\n  Checking if rings are identical (ring0 == ring2)...";
        ring0 == ring2 ? 
            cout << "\n  [TRUE] ring0 == ring2" : 
            cout << "\n  [FALSE] ring0 =/= ring2";

    cout << endl;
    system("pause");

    cout << "\n ======== Testing \"=\" operator overload :===========";
        cout << ring0 << ring1 << ring2;
        cout << "\n  Copying rings...";
        ring0 = ring1 = ring2;
        cout << ring0 << ring1 << ring2;

    cout << "\n ==== Testing constructors (dynamic objects) ==== ";
    Ring *ptr_ring0, *ptr_ring1, *ptr_ring2, *ptr_ring3;

        ptr_ring0 = new Ring(75, 85);
        ptr_ring1 = new Ring(70, 80);
        ptr_ring2 = new Ring(71, 81, 9, 11);
        ptr_ring3 = new Ring();

    cout << endl;
    system("pause");

    cout << "\n == Testing ++ and -- operators overload (dynamic objects) == ";
        cout << "\n  Enter new ring parameters: ";
        cin >> *ptr_ring0;

        cout << "\n  Increasing the ptr_ring...";
        ++(*ptr_ring0);
        cout << "\n  Increasing the ptr_ring...";
        ++(*ptr_ring0);
        cout << ptr_ring0;
        cout << "\n  Decreasing the ptr_ring...";
        --(*ptr_ring0);
        cout << ptr_ring0;

    cout << endl;
    system("pause");

    cout << "\n === Testing (ptr_ring 1 + ptr_ring 2) (dynamic objects) ===";
        cout << ptr_ring1 << ptr_ring2;

        cout << "\n  Summing ptr_rings...";
        cout << (*ptr_ring1 + *ptr_ring2);

    cout << endl;
    system("pause");



    cout << "\n === Testing (ptr_ring 2 - ptr_ring 3) (dynamic objects) ===";
        cout << ptr_ring3;
        cout << ptr_ring2;
        cout << "\n  Substracting ptr_rings...";
        cout << (*ptr_ring2 - *ptr_ring3);
        cout << endl;
    system("pause");



    cout << "\n === Testing > and < operators overload (dynamic objects) ===";
        cout << *ptr_ring0 << *ptr_ring2;

        cout << "\n  ptr_Comparing ptr_Rings... (>)";
        (*ptr_ring0 > *ptr_ring2) ? 
            cout << "\n  [TRUE]  ptr_ring0 > ptr_ring2" : 
            cout << "\n  [FALSE] ptr_ring0 < ptr_ring2";

        cout << "\n  ptr_Comparing ptr_Rings...(<)";
        (*ptr_ring0 < *ptr_ring2) ? 
            cout << "\n  [TRUE] ptr_ring0 < ptr_ring2" : 
            cout << "\n  [FALSE] ptr_ring0 > ptr_ring2";

    cout << endl;
    system("pause");



    cout << "\n === Testing \"==\" operator overload (dynamic objects) ===";
        cout << ptr_ring0 << ptr_ring1 << ptr_ring2;

        cout << "\n  Checking if (ptr_ring1 == ptr_ring1)...";
        *ptr_ring0 == *ptr_ring1 ?
            cout << "\n  [TRUE] ptr_ring0 == ptr_ring1" :
            cout << "\n  [FALSE] ptr_ring0 =/= ptr_ring1";

        cout << "\n  Checking if (ptr_ring0 == ptr_ring2)...";
        *ptr_ring0 == *ptr_ring2 ?
            cout << "\n  [TRUE] ptr_ring0 == ptr_ring2" :
            cout << "\n  [FALSE] ptr_ring0 =/= ptr_ring2";

    cout << endl;
    system("pause");



    cout << "\n === Testing \"=\" operator overload (dynamic objects) ===";
        cout << ptr_ring0 << ptr_ring1 << ptr_ring2;
        cout << "\n  Copying ptr_rings...";
        *ptr_ring0 = *ptr_ring1 = *ptr_ring2;
        cout << ptr_ring0 << ptr_ring1 << ptr_ring2;
}