/* 
Описать логическую функцию Is_letter (c),которая определит, является ли некий произвольный символ c(параметр функции) одной из строчных или заглавных букв русского алфавита. 
Обратиться к функции в диалоге, передавая ей посимвольно текст, вводимый с клавиатуры.
 */

#include <iostream>
#include <conio.h> //getche()

using namespace std;
bool is_letter(char ch);

int main()
{
    char ch = 0; //для исключения UB
    cout << "Enter a char: [EN] (Press ESC to exit) \n"; //введите символ

    while (ch != 27) //физическая ESС-клавиша
    {
        ch = getche();
        ( is_letter(ch) ) ? (cout << " == EN" << endl) : (cout << " != EN" << endl);  
    }

}

//check for en chars
bool is_letter (char c)
{
    bool result = (c>='a' && c<='z' || c>='A' && c<='Z')  ? (true) : (false); //
    return result;
}