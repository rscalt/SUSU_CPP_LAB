/* 
    Практическоезадание No 1. 
    Инкапсуляция
    1.Опишите класс «Длина» для измерения расстояний.
        Данные класса:число километров и метров, натуральные числа.
        Конструкторы класса:конструктор по умолчанию, конструктор округленного значения и конструктор произвольной длины.
    2.Определите методы:ввод длины, вывод на экран, определение длины в метрах 
        и метод приведения, если данные заданы некорректно.
    3.Объявите длину в километрах и произвольную длину как статические объекты
        созданного типа, найдите длину в метрах для каждого объекта.
    4.Объявите динамический объект по умолчанию, введите данные 
        и выведите на экран
    5.Объявите массив из 2-3 длин. 
        Найдите способ присвоить им значения при создании объектов. 
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
////////////////////////////////////////////////////////
void pause();

class Distance
{
private:
    //cчетчик
    static unsigned int id;
    //наименование маршрута
    string name;
    //километры
    unsigned int km;
    //метры
    unsigned int m;
    //ширина ячейки в символах (для вывода)
    unsigned int cell_width = 12;

    //проверка ввода (на соответствие типу данных)
    void loop_check_buffer(int &input_buffer)
    {
        while (cin.fail() || input_buffer < 0)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            errorMsg(-1);

            cout << "\nPlease, enter again: \n";
            cin >> *(&input_buffer);
        }
    }

    //проверка ввода (на корректность ввода метров)
    int fix_values(unsigned int &km_value,
                   unsigned int &m_value)
    {

        if (m_value >= 1000)
        {
            //сколько добавить к километрам за счет приведения метров
            double add_to_km = 0;
            add_to_km = floor(m_value / 1000);

            //приведенное значение метров
            unsigned int valid_m = 0;
            valid_m = m_value - add_to_km * 1000;

            //хакерскую эзотерику отбрасываем
            if (add_to_km >= 1000)
            {
                cout << "\nPlease, care entering valid values.";
                exit(-1);
            }

            m_value = valid_m;
            km_value += add_to_km;

            //если значения были исправлены
            return add_to_km;
        }
        //если значения остались без изменений
        else
            return 0;
    }

    //сообщения об ошибках
    void errorMsg(int error_code)
    {
        switch (error_code)
        {
        case -1:
            cout << " Invalid value.";
            cout << " Only positive integer values are accepted \n";
            break;

        default:
            cout << "Unknown error";
            break;
        }
    }

public:
    //===//===//===//===//===//===//===//===//===//===

    //конструктор по умолчанию
    Distance() : name("Default"), km(0), m(0)
    {
        name += to_string(++id);
        cout << "\n\n";
        cout << "Distance \"" << name << "\" have been created!";
    }

    //конструктор произвольного значения
    Distance(unsigned int arg1,
             unsigned int arg2,
             string name_custom) : km(arg1), m(arg2)
    {

        name = name_custom + to_string(++id);
        cout << "\n\n";
        cout << "Distance \"" << name << "\" have been created!";
    }

    //конструктор округленного значения
    Distance(float arg1,
             float arg2,
             string name_rounded) : km(round(arg1)), m(round(arg2))
    {
        name = name_rounded + to_string(++id);
        cout << "\n\n";
        cout << "Distance \"" << name << "\" have been created!";
    }
    //===//===//===//===//===//===//===//===//===//===

    //произвольный ввод
    void setData();
    //вывод
    void showData() const;
    //перевод в метры
    unsigned int getMeters() const;
};
unsigned int Distance::id = 0;
////////////////////////////////////////////////////////
int main()
{

    pause();
    cout << "\n============ Task 3 ==============";
    Distance distance1;
    distance1.showData();
    distance1.getMeters();

    Distance distance2(10U, 20U, "Custom");
    distance2.showData();
    distance2.getMeters();
    
    Distance distance3(30.55F, 20.45F, "Rounded");
    distance3.showData();
    distance3.getMeters();

    pause();
    cout << "\n============ Task 4 ==============";
    Distance *distance_pointer = new Distance;
    cout << "\nNew object is at " << distance_pointer;
    distance_pointer->setData();
    distance_pointer->showData();
    
    pause();
    cout << "\n============ Task 5 ==============";
    Distance distance_array[3];
    for (int i = 0; i < 3; i++)
        distance_array[i].showData();

}

void Distance::setData()
{
    //промежуточный буфер для проверки ввода
    int buffer;

    //здесь для string проверка не требуется
    cout << "\nRoute name: \n";
    cin >> name;

    cout << "\nKilometers: \n";
    cin >> buffer;
    //сперва проверим сам буфер
    loop_check_buffer(buffer);
    //в случае успешной проверки
    km = buffer;

    cout << "\nMeters: \n";
    cin >> buffer;
    //сперва проверим сам буфер
    loop_check_buffer(buffer);
    //в случае успешной проверки
    m = buffer;

    //проверяем корректность ввода метров
    int values_fixed = 0;
    values_fixed = fix_values(km, m);
    if (values_fixed)
    {
        cout << "\n";
        cout << "Invalid meters value found (>=1000).";
        cout << "\n";
        cout << "Both kilometers and meters values have been fixed.";
        cout << "\n";
        cout << "Kilometres added: " << values_fixed;
        cout << "\n";
    }
}

void Distance::showData() const
{
    cout << "\n";
    cout << setw(cell_width) << setfill(' ') << "Name"
         << "\t";
    cout << setw(cell_width) << setfill(' ') << "Kmeters"
         << "\t";
    cout << setw(cell_width) << setfill(' ') << "Meters"
         << "\t";
    cout << "\n";
    cout << setw(cell_width) << setfill(' ') << name << "\t";
    cout << setw(cell_width) << setfill(' ') << km << "\t";
    cout << setw(cell_width) << setfill(' ') << m << "\t";
}

unsigned int Distance::getMeters() const
{
    unsigned int meters_amount = 0;
    meters_amount = (this->km) * 1000 + (this->m);
    cout << "\n";
    cout << "Distance \"" << this->name << "\" is ";
    cout << meters_amount;
    cout << " meters long";
    return meters_amount;
}

void pause()
{
    cout << "\n";
    system("pause");
    cout << "\n";
}