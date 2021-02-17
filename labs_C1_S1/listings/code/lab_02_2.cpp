/*
Упражнение 2. Выбор одной из трех возможный ситуаций
Запишите код программы для решения задачи. 
Рекомендуемый вес человека определяется как (Рост(см) – 100) +/-5%. 
Ввести рост и вес, 
сравнить с рекомендуемым 
и вывести рекомендательное сообщение, например, «Необходимо похудеть на Х кг.».
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    unsigned short height, weight;
    cout << "Enter height (cm):\n";
    cin >> height; //рост
    cout << "Enter weight (kg):\n";
    cin >> weight; //вес
    cout << "Height is " << height << "\nWeight is " << weight << "\n";

    unsigned short weight_check;
    weight_check = height - 100;
    cout << "Weight recommended is " << weight_check << "\n";
    double delta;
    delta = 0.05;
    cout << "Delta is " << delta << "\n";

    float weight_max = weight_check*(1+delta);
    weight_max = round(weight_max);
    cout << "Max weight is " << weight_max << "\n";
    float weight_min = weight_check*(1-delta);
    cout << "Min weight is " << weight_min << "\n";
    weight_min = round(weight_min);

    if ( weight < weight_min )
    {
        int weight_deficit = weight_min - weight;
        cout << "Get fat! " << "(+) " << weight_deficit << " kg!\n";
    }

    else 
    if ( weight > weight_max )
    {
        int weight_proficit = weight - weight_max;
        cout << "Get slim! " << "(-) " << weight_proficit << " kg!\n";
    }

    else
    {
        cout << "Weight is OK.\n";
    }

    system("pause");
    system("cls");
}