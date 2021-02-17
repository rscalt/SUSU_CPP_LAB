/* Дано натуральное число N, в записи которого ровно пять знаков. 
Определить, является ли это число палиндромом или нет, напечатать сообщение текстом.Проверить условие принадлежности числа интервалу допустимых значений. */
/* Значение числа вводить в диалоге, иметь возможность повторного обращения. */

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int max_n = 99999;
    int min_n = 10000;
    int d1 = 0; //единицы 1
    int d2 = 0; //десятки 10 
    int d3 = 0; //сотни 100 
    int d4 = 0; //тысячи 1 000
    int d5 = 0; //десятки тысяч 10 000
    char restart_char = 'n';
    
    do 
    {
        restart_char = 'n';
        n = 0;
        cout << "Enter natural N of 5-digits: \n";
        cin >> n;
        
        if (n >= min_n && n <= max_n)
            {
            d1 = n%10; //единицы
            d2 = (n%100 - d1)/10;
            d3 = (n%1000 - d2 - d1)/100; //сотни
            d4 = (n%10000 - d3 - d2 - d1)/1000; 
            d5 = (n - d4*1000 - d3*100 - d2*10 - d1*1)/10000; //десятки тысяч
            cout << d1 << d2 << d3 << d4 << d5;

            if (d1 == d5 && d2 == d4)
                {
                cout << " is a palindrome! <TRUE>\n";
                cout << "Restart? (y,n)\n";
                cin >> restart_char;
                }
            else 
                {
                cout << " is not a palindrome! <FALSE>\n";
                cout << "Restart? (y,n)\n";
                cin >> restart_char;
                }
            }
        else 
            {
            cout << "Wrong input...\n";
            cout << "Restart? (y,n)\n";
            cin >> restart_char;
            }
    } while (restart_char == 'y');
    



}