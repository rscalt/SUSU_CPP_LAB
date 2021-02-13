/* Дана матрица размером n*m. 
Найти и заменить нулем максимальное и минимальное значения в каждой строке матрицы. Использовать функцию, находящую минимум, и функцию, находящую максимум из элементов одномерного массива. Передавать им по очереди строки матрицы. */

#include <iostream>
#include <iomanip>

using namespace std;

const int total_rows = 3; //строк
const int total_columns = 4; //столбцов
const int element_count = total_rows*total_columns;

bool warning_flag = false; //единожды уведомили пользователя по поводу флагов удаления

void enter_matrix(int *matrix, int total_rows = total_rows, int total_columns = total_columns); //заполнение матрицы случайными значениями от 0 до 20
void print_matrix(int *matrix, int element_count = element_count); //вывод на печать
int row_find_max(int *matrix, int selected_row, bool return_index, int total_columns = total_columns); //максимальный элемент переданной строки
int row_find_min(int *matrix, int selected_row, bool return_index, int total_columns = total_columns); //минимальный элемент переданной строки
void nullify_row_at_index(int *matrix, int selected_row, int total_columns = total_columns);


int main()
{
    cout << "\nInitializing matrix: \n";
    int matrix[total_rows*total_columns] = {}; //матрица из n*m элементов
    print_matrix(matrix); //параметры по умолчанию - в объявлении
    cout << endl;


    cout << "\nRandom-filled matrix:\n"; //
    enter_matrix(matrix); //параметры по умолчанию - в объявлении
    print_matrix(matrix); //параметры по умолчанию - в объявлении
    cout << endl;

    cout << "\nMax and Min of each row:\n";
    for (int row = 1; row <= total_rows; row++) //передаем строки по очереди и смотрим значения
    {
        cout << row_find_max(matrix, row, false) << " ";
        cout << row_find_min(matrix, row, false) << " ";     
        cout << "\n";
    }   
        
        

    cout << "\nNullifying max and min for each row...\n";
    for (int row = 1; row <= total_rows; row++) //передаем строки по очереди и удаляем значения
        nullify_row_at_index(matrix, row);
    cout << "Done!\n";

    cout << "\nNew matrix: ";
    print_matrix(matrix);

}
 //заполнение матрицы случайными значениями от 10 до 100
void enter_matrix(int *matrix, int total_rows, int total_columns)
{
    srand(time(NULL));
    int current_row_index = 0;
    int current_column_index = 0;

    for (current_row_index = 0; current_row_index < total_rows; current_row_index++)
        for (current_column_index = 0; current_column_index < total_columns; current_column_index++)
            *(matrix + current_row_index*total_columns + current_column_index) = 10 + (rand())%90; //разыменование адреса
}

 //вывод
void print_matrix(int *matrix, int element_count)
{
    for (int i = 0; i < element_count-1; i++) //в цикле - вывод без последнего элемента
    {
        if ((i%total_columns) == 0)
            cout << endl;
        cout << matrix[i] << " ";
    }
    cout << matrix[element_count-1]; //вне цикла - последний элемент, без запятой
}

int row_find_max(int *matrix, int selected_row, bool return_index, int total_columns)
{
        int selected_row_index = selected_row - 1; //индекс переданной строки
        int row_max =  *(matrix + total_columns*selected_row_index + 0); // arr[selected_row_index][0]
        int index_of_row_max = 0; //индекс элемента для удаления
        

        for (int current_column_index = 1; current_column_index < total_columns; current_column_index++) //со второго элемента строки
        {
            if ( *(matrix + selected_row_index*total_columns + current_column_index) > row_max)
                {
                row_max = *(matrix + selected_row_index*total_columns + current_column_index);
                index_of_row_max = current_column_index;
                }
        }

        if (return_index == true)
            return index_of_row_max;
        else
            return row_max;
}


int row_find_min(int *matrix, int selected_row, bool return_index, int total_columns)
{
        int selected_row_index = selected_row - 1; //индекс переданной строки
        int row_min =  *(matrix + total_columns*selected_row_index + 0); // arr[selected_row_index][0]
        int index_of_row_min = 0; //индекс элемента для удаления
        

        for (int current_column_index = 1; current_column_index < total_columns; current_column_index++) //со второго элемента строки
        {
            if ( *(matrix + selected_row_index*total_columns + current_column_index) < row_min)
                {
                row_min = *(matrix + selected_row_index*total_columns + current_column_index);
                index_of_row_min = current_column_index;
                }
        }

        if (return_index == true)
            return index_of_row_min;
        else
            return row_min;
}

void nullify_row_at_index(int *matrix, int selected_row, int total_columns)
{

    int selected_row_index = selected_row - 1; //индекс переданной строки
    int column_index_to_nullify = 0;

    column_index_to_nullify = row_find_min(matrix, selected_row, true);
    *(matrix + selected_row_index*total_columns + column_index_to_nullify) = 0;

    column_index_to_nullify = 0;

    column_index_to_nullify = row_find_max(matrix, selected_row, true);
    *(matrix + selected_row_index*total_columns + column_index_to_nullify) = 0;
}