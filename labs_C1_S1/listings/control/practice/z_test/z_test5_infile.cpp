/* Валяльная фабрика производит валенки. 
Данные об объемах сбыта продукции и о ценах продаж за прошлый год помесячно 
хранятся в файле в виде таблицы.
При подведении итогов года необходимо выяснить динамику сбыта, то есть найти и упорядочить по убыванию информацию о прибылях, приносимых производством. 
Использовать функцию для вычисления ежемесячной прибыли. 
Для сортировки матрицы по столбцу «прибыль» использовать функцию сортировки матрицы методом пузырька.  */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

enum month //месяцы
{
    Jan, Feb, Mar, 
    Apr, May, Jun, 
    Jul, Aug, Sep,
    Oct, Nov, Dec
};

//продажи соответствующего месяца
class month_sales 
    {
    protected:
        int id;
        char* month;
        int volume;
        int price;
        int costs;
    public:
        void getMonth()
        {
        cout << "\n Enter month: "; cin >> id >> month >> volume >> price >> costs;
        }
        void showMonth(void)
        {
        cout << "\n Month data is: " << id << month << volume << price << costs;
        }
    };

//пусть исходные данные передаются в виде csv-файла (строки и столбцы разделяются символом ';')
//и сохраняются в одной папке с программой
// + данные по каждому году хранятся в отдельном файле
//например, файл "db_sales_2020.csv"
//пусть технические условия допускают выделение памяти ~= размеру одного файла

int main()
{
    int rows = 12+1;
    int columns = 5+1;
    ifstream infile("db_sales_2020.csv", ios::out); //явное открытие только для чтения
    char delimeter = ';'; //разделитель колонок csv-файла

    int id, month, volume, price, costs;

    int cell_counter = 0;
    int row_counter = 0;
    int column_counter = 0;

    string str_buffer;
    //int buffer_cout_counter = 1;

    string array[rows][columns] =  {};



    while (infile.peek() != EOF) 
    {
        stringstream str_line_buffer;
        //getline(infile, str_line_buffer);
        getline(str_line_buffer, str_buffer);

        //cout << "\n";
        //cout << "buffered count: "<< buffer_cout_counter++ << "_";
        cout << str_buffer;
        cout << "=";
        
        cout << "L:_";
        cout << cell_counter;
        cout << "_R:_";
        cout << row_counter;
        cout << "_C:_";
        cout << column_counter; 

    
        cell_counter++;

        if ((cell_counter%columns) == 0)
        {
            column_counter = columns;
            row_counter++;
        }
        else column_counter = cell_counter%columns;

        cout << "||";
        
        
        array[row_counter][column_counter] = str_buffer;
    }
        int i = 0;
        int j = 0;

        cout << endl;
        for (i = 0; i < rows; i++)
        {
            //cout << "\n";
            for (j = 0; j < columns; j++)
                cout << array[i][j] << "_";
        }

    return 0;
    
}