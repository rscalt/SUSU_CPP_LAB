/* 
Ученица швеи начинает работу, сострачивая в день 2 пары рукавиц. Совершенствуя свое мастерство, она каждый день выполняет в два раза больше работы, чем в предыдущий день. Больше, чем 100 пар в день, сострочить нельзя.
Найти, на который день ученица достигнет вершин мастерства. 
Сколько пар рукавиц ей при этом придется сшить? 
Вывести на экран таблицу роста мастерства швеи по дням
 */

#include <iostream>

using namespace std;

int main()
{
    int base_mastery = 2; //начальное мастерство, пар.
    int growth_rate = 2; //коэффициент роста мастерства (к предыдущему дню)
    int day = 0;
    int total_quantity = 0;
    int current_mastery = base_mastery;
    int max_mastery = 100; //вершина мастерства, пар.
    
    cout << "day \t" << "mastery \t" << "total_quantity" << endl;
    while (current_mastery < max_mastery)
        { //за каждый день:
        current_mastery *= growth_rate; //рост мастерства
        if (current_mastery > max_mastery) current_mastery = max_mastery; //проверка на непревышение


        total_quantity += current_mastery; //сделано пар, ИТОГО
        day++; //начинается следующий день
        cout << day << "\t" << current_mastery << "\t\t" << total_quantity <<  endl;
        }
    
    cout << endl; //результаты
    cout << " Max mastery = " << max_mastery
         << " at day = "      << day
         << " with total = "  << total_quantity; 
    cout << endl;
}