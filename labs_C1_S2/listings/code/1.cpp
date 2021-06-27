#include <iostream>
#include <math.h>
using namespace std;
////////////////////////////////////////////////////////
class length
{
private:
    //наименование маршрута
    string name;
    //километры
    unsigned int km;
    //метры
    unsigned int m;

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
            valid_m = m_value - add_to_km*1000;

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
    //ввод
    void getData()
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
    //вывод
    void showData()
    {
        cout << "\n";
        cout << "Name: " << name << "\n"
             << "Kilometers: " << km << "\n"
             << "Meters: " << m << "\n";
        cout << "\n";
    }
};
////////////////////////////////////////////////////////
int main()
{
    length route1, route2;
    route1.getData();
    route2.getData();

    route1.showData();
    route2.showData();
}