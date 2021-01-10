/*
Упражнение 2.2. Простой итерационный цикл
Составить программу для определения наибольшего общего делителя (НОД) 
двух простых чисел m и n  
по алгоритму Евклида
*/

// натуральные же, а не простые?

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int main()
{   
    int m, n, counter;

    do //для возможности рестарта
    {   
        cout << "Enter numbers (m, n) : m > n \n";
        cin >> m;
        cin >> n;
        counter = 1; // для логов

        cout << "iteration  #"<< "\tm\t" << "n\t" "m%n\n"; //шапка таблицы
        while (n) {
            cout << "iteration: " << counter << "\t" << m << "\t" << n  << "\t" << m%n << "\n"; 
            //строки по каждой Евклидовой итерации
            m %= n;
            swap (m, n);
            counter++; // для логов
        }

        cout << "=========================\n";
        cout << "Result is " << m << "\n"; //наибольший общий делитель
        cout << "Press ESC to exit, or press any other key to restart...\n\n";

    } while (_getch() != 27); //управление событием из упражнения 2.3

}
