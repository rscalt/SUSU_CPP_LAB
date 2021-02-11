/* Дана матрица размером n*m. 
Найти и заменить нулем максимальное и минимальное значения в каждой строке матрицы. Использовать функцию, находящую минимум, и функцию, находящую максимум из элементов одномерного массива. Передавать им по очереди строки матрицы. */

#include <iostream>
#include <iomanip>

using namespace std;

const int matrix_rows_total = 3;
const int matrix_columns_total = 4;

void print_array_string(float *arr, int arr_length);
void print_matrix(float matrix[matrix_rows_total][matrix_columns_total], const int &matrix_rows_total, const int &matrix_columns_total);
void enter_matrix(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total);
float *array_of_max(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total, float *row_max);
float find_max(float *row_max, int matrix_rows_total);
float *array_of_min(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total, float *row_min);
float find_min(float *row_max, int matrix_rows_total);
void null_max(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total);




int main()
{   
    float matrix[matrix_rows_total][matrix_columns_total] = {};

    cout << "\nInitializing matrix: \n";
    print_matrix(matrix, matrix_rows_total, matrix_columns_total);
    
    cout << "\nEnter the matrix: \n";
    enter_matrix(matrix, matrix_rows_total, matrix_columns_total);

    cout << "\nThe matrix is: \n";
    print_matrix(matrix, matrix_rows_total, matrix_columns_total);

    cout << "\nThe array of row max INDEXEX is: \n";
    float *indexes_of_row_max_ptr = new float[matrix_rows_total]();
    indexes_of_row_max_ptr = array_of_max(matrix, matrix_rows_total, matrix_columns_total, indexes_of_row_max_ptr);
    print_array_string(indexes_of_row_max_ptr, matrix_rows_total);

    cout << "\nThe array of row min INDEXEX is: \n";
    float *indexes_of_row_min_ptr = new float[matrix_rows_total]();
    indexes_of_row_min_ptr = array_of_min(matrix, matrix_rows_total, matrix_columns_total, indexes_of_row_min_ptr);
    print_array_string(indexes_of_row_min_ptr, matrix_rows_total);


    cout << "\n MAX of array of row max values is: \n";
    cout << find_max(indexes_of_row_max_ptr, matrix_rows_total);
    cout << "\n MIN of array of row min values is: \n";
    cout << find_min(indexes_of_row_min_ptr, matrix_rows_total);

}

void print_matrix(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total )
{
    for (int current_row = 0; current_row < mx_rows_total; current_row++)
        for (int current_column = 0; current_column < mx_columns_total; current_column++)
        {
            if ( (current_column%mx_columns_total == 0) && (current_row != 0) )
                cout << endl;
            cout << matrix[current_row][current_column] << " ";
        }
}

void enter_matrix(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total)
{
    int current_row = 0;
    int current_column = 0;

    for (current_row = 0; current_row < mx_rows_total; current_row++)
        for (current_column = 0; current_column < mx_columns_total; current_column++)
        //system("cls");
        {
            /* cout << "[" << current_row << "]"
                    << "[" << current_column << "]"
                    << ": " << endl; 
            */
            //cin >> matrix[current_row][current_column];
            matrix[current_row][current_column] = rand()%100;
        }
}

//обнуляет максимальный элемент матрицы
void null_max(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total, float *row_max)
{
/*     int current_row = 0;
    int current_column = 0;
    int last_row = mx_rows_total-1;
    int last_column = mx_columns_total-1;

    for (current_row = 0; )
 */
}

float *array_of_max(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total, float* indexes_of_row_min)
{
    int current_row = 0;
    int current_column = 0;
    int last_row = mx_rows_total-1;
    int last_column = mx_columns_total-1;

    for (current_row = last_row; current_row >= 0; current_row--)
    {   
        indexes_of_row_min[current_row] = matrix[current_row][last_column];
        for (current_column = last_column; current_column > 0; current_column--)   
            {
                if (matrix[current_row][current_column-1] > indexes_of_row_min[current_row])
                indexes_of_row_min[current_row] = current_column-1;
            }
    }
    return indexes_of_row_min;
}

float *array_of_min(float matrix[matrix_rows_total][matrix_columns_total], const int &mx_rows_total, const int &mx_columns_total, float* indexes_of_row_min)
{
    int current_row = 0;
    int current_column = 0;
    int last_row = mx_rows_total-1;
    int last_column = mx_columns_total-1;

    indexes_of_row_min[current_row] = matrix[current_row][last_column];

    for (current_row = last_row; current_row >= 0; current_row--)
    {  
        indexes_of_row_min[current_row] = matrix[current_row][last_column];
        for (current_column = last_column; current_column > 0; current_column--)
        { 
            if (matrix[current_row][current_column-1] < indexes_of_row_min[current_row])
                indexes_of_row_min[current_row] = current_column-1;
        }
    }
    return indexes_of_row_min;
}

void print_array_string(float *arr, int arr_length)
{
    for (int i = 0; i < arr_length-1; i++)
        cout << arr[i] << ", ";
    cout << arr[arr_length-1];
}

float find_min(float *row_min, int matrix_rows_total)
{
    float min_row_min = row_min[matrix_rows_total];
    for (int i = matrix_rows_total; i > 0; i--)
        if (row_min[i-1] < min_row_min )
            min_row_min = row_min[i-1];

    return min_row_min;
}

float find_max(float *row_max, int matrix_rows_total)
{
    float max_row_max = row_max[matrix_rows_total];
    for (int i = matrix_rows_total; i > 0; i--)
        if (row_max[i-1] > max_row_max )
            max_row_max = row_max[i-1];

    return max_row_max;
}