#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int rows = 16;
const int columns = 16;
const int MAX = rows * columns;
int buff[MAX]{};

int main()
{
    //заполнение массива
    for (int j = 0; j < MAX; j++)
        buff[j] = j;

    //вывод линейного массива в виде таблицы
    for (int row_ind = 0; row_ind < rows; row_ind++)
    {
        cout << "\n";

        for (int col_ind = 0; col_ind < columns; col_ind++)
            cout << uppercase << setfill('0') << hex << setw(2)
                 << buff[row_ind * columns + col_ind] << " ";
    }

    //запись в файл
    ofstream data;
        data.open("edata.bin", ios::binary);
        data.write(reinterpret_cast<char*>(buff), MAX*sizeof(int));
        data.close();

    //очистка массива
    for (int j = 0; j < MAX; j++)
    buff[j] = 0;

}
