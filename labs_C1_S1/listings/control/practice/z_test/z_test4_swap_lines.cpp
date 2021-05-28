#include <iostream>
#include <iomanip>
using namespace std;

const int cout_width = 3;
const int total_lines = 3;
const int total_columns = 3;

void cout_matrix(long array[total_lines][total_columns]);
void fill_matrix(long array[total_lines][total_columns]);
void swap_pointers(long *ptr_1, long *ptr_2, long n);

int main()
{
    long arr[total_lines][total_columns] = {};

    cout_matrix(arr);

    fill_matrix(arr);

    cout << endl;
    cout_matrix(arr);

    swap_pointers(arr[0], arr[1], total_columns);

    cout << endl;
    cout_matrix(arr);
}

void swap_pointers(long *ptr_1, long *ptr_2, int total_columns)
{
    for (long i = 0; i < total_columns; i++)
    {
        double tmp = ptr_1[i];
        ptr_1[i] = ptr_2[i];
        ptr_2[i] = tmp;
    }
}

void cout_matrix(long array[total_lines][total_columns])
{
    for (int line_index = 0; line_index < total_lines; line_index++)
    {
        cout << "\n";
        for (int column_index = 0; column_index < total_columns; column_index++)
            cout << setw(cout_width) << array[line_index][column_index] << " ";
    }
}

void fill_matrix(long array[total_lines][total_columns])
{
    for (int line_index = 0; line_index < total_lines; line_index++)
        for (int column_index = 0; column_index < total_columns; column_index++)
            array[line_index][column_index] = (line_index)*total_columns + column_index;
}