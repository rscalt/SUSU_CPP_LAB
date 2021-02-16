/* Валяльная фабрика производит валенки. 
Данные об объемах сбыта продукции и о ценах продаж за прошлый год помесячно 
хранятся в файле в виде таблицы.
При подведении итогов года необходимо выяснить динамику сбыта, то есть найти и упорядочить по убыванию информацию о прибылях, приносимых производством. 
Использовать функцию для вычисления ежемесячной прибыли. 
Для сортировки матрицы по столбцу «прибыль» использовать функцию сортировки матрицы методом пузырька.  */

#include <fstream> //class ifstream
#include <iostream>
#include <iomanip>
#include <string>  //class string
#include <sstream> //class stringstream

using namespace std;

const int total_lines = 12;      //всего строк //месяцы
string month_enum[total_lines] = //месяцы
    {
        "Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"};

const int total_columns = 5;       //столбцы
const int column_id = 1;           //номер колонки: id строки *БД*
const int column_month = 2;        //номер колонки: месяц
const int column_sales_volume = 3; //номер колонки: объем продаж, пар
const int column_price = 4;        //номер колонки: цена продажи пары
const int column_costs = 5;        //номер колонки: стоимость производства пары

int array_length = total_lines * total_columns; //всего элементов в csv-массиве

const int profit_array_columns = 2; //колонок в матрице прибылей по месяцам
const int profit_column_id = 1;     //номер колонки: "месяц"
const int profit_column_profit = 2; //номер колонки: "прибыль"
//====================================================================================
void cout_matrix(string csv_array_as_matrix[total_lines][total_columns],
                 int total_lines = total_lines,
                 int total_columns = total_columns);

void cout_matrix(int profit_array[total_lines][profit_array_columns]);
void cout_array(string *csv_array_as_line, int array_length = array_length);
void cout_profit(long profit_array[total_lines][profit_array_columns]);

long calc_profit(int &month_sales, int &month_price, int &month_costs);

void bubble_sort_desc(long profit_array[total_lines][profit_array_columns]);
void bubble_sort_desc(string array[total_lines][total_columns], int selected_column);

void swap_content_between_lines(long array[][profit_array_columns], int first_line_index, int second_line_index, int column_number);
void swap_values(long &a, long &b);
//====================================================================================

//getline(файл) -> getline(строка файла) -> ячейка таблицы
int main()
{
  string filename = "db_sales_2020.csv"; //имя файла
  ifstream data;                         //поток данных из файла
  data.open(filename, ios::out);         //файл только для чтения

  string line;                       //строка таблицы
  string csv_array_as_line[12 * 5];  // линейный массив считанных данных
  string csv_array_as_matrix[12][5]; // матричный массив считанных данных

  int read_cell_count = 0; //число считанных ячеек

  // data >> line при каждой итерации; getline(data, line) = 0 при EOF
  while (getline(data, line))
  {

    stringstream line_stream(line); //строка в виде потока
    string cell;                    //ячейка

    while (getline(line_stream, cell, ';')) //строка в виде потока (до разделителя ';') >> ячейка
    {
      read_cell_count++;                             //для отладки
      csv_array_as_line[read_cell_count - 1] = cell; //линейный csv-массив
    }
  }

  //из линейного массива заполняем матричный
  for (int line_index = 0; line_index < total_lines; line_index++)
    for (int column_index = 0; column_index < total_columns; column_index++)
      csv_array_as_matrix[line_index][column_index] = csv_array_as_line[line_index * total_columns + column_index];

  //вывод линейного csv-массива
  //cout_array(csv_array_as_line);

  //вывод csv-матрицы
  cout << endl;
  for (int line_index = 0; line_index < total_lines; line_index++)
  {
    cout << "\n";

    for (int column_index = 0; column_index < total_columns; column_index++)
      cout << csv_array_as_matrix[line_index][column_index] << "\t";
  }

  //заполняем матрицу прибылей
  long profit_array[total_lines][profit_array_columns] = {}; // ...[2] : id, profit
  for (int line_index = 0; line_index < total_lines; line_index++)
  {
    //присваиваем значения
    string month_sales_str = csv_array_as_matrix[line_index][column_sales_volume - 1];
    string month_price_str = csv_array_as_matrix[line_index][column_price - 1];
    string month_costs_str = csv_array_as_matrix[line_index][column_costs - 1];
    string id_str = csv_array_as_matrix[line_index][column_id - 1];

    //для преобразования
    int month_sales = 0;
    int month_price = 0;
    int month_costs = 0;
    int id = 0;

    //строку как поток символов передаем в int
    stringstream(month_sales_str) >> month_sales;
    stringstream(month_price_str) >> month_price;
    stringstream(month_costs_str) >> month_costs;
    stringstream(id_str) >> id;

    long profit = calc_profit(month_sales, month_price, month_costs);
    profit_array[line_index][profit_column_id - 1] = id; //значения не упорядочены
    profit_array[line_index][profit_column_profit - 1] = profit;
  }

  //вывод матрицы месячной прибыли
  cout << endl;
  cout << endl;
  cout_profit(profit_array);

  bubble_sort_desc(profit_array);

  cout << endl;
  cout_profit(profit_array);
}

//вывод csv-матрицы
void cout_matrix(string csv_array_as_matrix[total_lines][total_columns], int total_lines, int total_columns)
{
  for (int line_index = 0; line_index < total_lines; line_index++)
  {
    cout << "\n";

    for (int column_index = 0; column_index < total_columns; column_index++)
      cout << csv_array_as_matrix[line_index][column_index] << "\t";
  }
}

//вывод матрицы прибылей (перегрузка)
void cout_matrix(int profit_array[total_lines][profit_array_columns])
{
  for (int line_index = 0; line_index < total_lines; line_index++)
  {
    cout << "\n";
    for (int column_index = 0; column_index < profit_array_columns; column_index++)
      cout << profit_array[line_index][column_index] << "\t";
  }
}

//вывод линейного csv-массива
void cout_array(string *csv_array_as_line, int array_length)
{
  for (int i = 0; i < array_length; i++)
    cout << i << ": " << csv_array_as_line[i] << endl;
}

//вывод матрицы помесячной прибыли (месяц, прибыль)
void cout_profit(long profit_array[total_lines][profit_array_columns])
{
  for (int line_index = 0; line_index < total_lines; line_index++)
  {
    int id;
    string month;
    long profit;

    id = profit_array[line_index][profit_column_id - 1];
    month = month_enum[id - 1];
    profit = profit_array[line_index][profit_column_profit - 1];

    cout << "id: "
         << setw(3) << id << ": "
         << "\t";
    cout << month << "\t";
    cout << setw(8) << profit << endl;
  }
}

//расчет прибыли
long calc_profit(int &month_sales, int &month_price, int &month_costs)
{
  long month_profit = 0;

  month_profit = month_sales * (month_price - month_costs);
  return month_profit;
}

//сортировка пузырьком (по убыванию) //для прибылей
void bubble_sort_desc(long profit_array[total_lines][profit_array_columns])
{
  for (int i = 0; i < total_lines - 1; i++)   //максимальное смещение: на один индекс
    for (int j = 0; j < total_lines - 1; j++) //в худшем случае таких смещений нужно по общему числу элементов
    {
      for (int line_index = 0; line_index < total_lines; line_index++)
        if (profit_array[line_index + 1][profit_column_profit - 1] > profit_array[line_index][profit_column_profit - 1])
        {
          swap_content_between_lines(profit_array, line_index, line_index + 1, profit_column_profit);
          swap_content_between_lines(profit_array, line_index, line_index + 1, profit_column_id);
        }
    }
}

//сортировка пузырьком (по убыванию) //для заданного столбца таблицы
void bubble_sort_desc(string array[total_lines][total_columns], int selected_column)
{
  for (int i = 0; i < total_lines - 1; i++)   //максимальное смещение: на один индекс
    for (int j = 0; j < total_lines - 1; j++) //в худшем случае таких смещений нужно по общему числу элементов
    {
      for (int line_index = 0; line_index < total_lines; line_index++)
        if (array[line_index + 1][selected_column - 1] > array[line_index][selected_column - 1])
        {
          swap_content_between_lines(array, line_index, line_index + 1, selected_column);
          swap_content_between_lines(array, line_index, line_index + 1, profit_column_id);
        }
    }
}
//переставляет значения a и b
void swap_values(long &a, long &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

//переставляет значения колонки (по номеру колонки) между указанными строками (по индексам строк)
void swap_content_between_lines(long array[][profit_array_columns], int first_line_index, int second_line_index, int column_number)
{
  int buffer_array_length;
  buffer_array_length = 1;

  long int *buffer_array_ptr = new long[buffer_array_length]();
  buffer_array_ptr[0] = array[first_line_index][column_number - 1];

  array[first_line_index][column_number - 1] = array[second_line_index][column_number - 1];
  array[second_line_index][column_number - 1] = buffer_array_ptr[0];
}

//переставляет значения колонки (по номеру колонки) между указанными строками (по индексам строк)
void swap_content_between_lines(string array[total_lines][total_columns], int first_line_index, int second_line_index, int column_number)
{
  int buffer_array_length;
  buffer_array_length = 1;

  string *buffer_array_ptr = new string[buffer_array_length]();
  buffer_array_ptr[0] = array[first_line_index][column_number - 1];

  array[first_line_index][column_number - 1] = array[second_line_index][column_number - 1];
  array[second_line_index][column_number - 1] = buffer_array_ptr[0];
}