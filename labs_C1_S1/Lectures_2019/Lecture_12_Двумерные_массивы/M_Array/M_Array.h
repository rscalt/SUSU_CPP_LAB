//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
const int N = 4;
const int M = 5;

using namespace std;
void print_matr(int matr[][M], int n, int m) //Особенность! длина строки-число
{
int i,j;
cout << "Is Matrix\n";
	 for (i=0; i<n; i++)
		 {
			 for(j=0; j<m; j++)
			     cout << matr[i][j] << " " ;
		     cout << endl;
		 }
}
// Перегруженная функция вывода: выводит данные в файл.
void print_matr(string File_name, int matr[][M], int n, int m) //Особенность! длина строки-число
{
	ofstream out;				// out - поток для записи.
	out.open(File_name);	    // Открыть файл для записи.
	if (out.is_open())
	{
		int i, j;
		out << "Is Matrix\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				out << matr[i][j] << " ";
			out << endl;
		}
		out.close();	// Чтобы сохранить.
	}	// Иначе можно переназначить на консоль. 
}
// Перегруженная функция ввода: вводит данные из файла.
void input_matr(string File_name,int matr[][M], int &n, int &m)
{
	ifstream in;				// in - поток для чтения.
	in.open(File_name);	    // Открыть файл для чтения.
	if (in.is_open())
	{
		int i, j;
		in >> n >> m;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				in >> matr[i][j];
	}// Иначе можно переназначить на ввод с консоли.
}
void input_matr(int matr[][M], int &n, int &m)
{
	int i, j;
	do {
		cout << "Input Rows & Columns " << N << M;
		cin >> n >> m;
	} while (n>5 || m>5);

	cout << "Input elements\n";
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
			cin >> matr[i][j];
}

/* Управление в алгоритмах работы с двумерными массивами -.
вложенные циклы, где управляющая переменая  -
номер строки во внешнем,
и столбца во внутреннем цикле для просмотра по строкам.
Или наоборот - просмотр по столбцам.
*/

void Sum_Rows(int matr[][M], int n, int m, int Sum[])
{
   int i,j;
   for (i=0; i<n; i++)
   {
   Sum[i]=0;
	  for(j=0; j<m; j++)
		 Sum[i] += matr[i][j];
	  matr[i][m++] = Sum[i];
   }
}
void Sum_Columns(int matr[][M], int n, int m, int Sum[])
{
   int i,j;
   for (j=0; j<m; j++)
   {
   Sum[j]=0;
	  for(i=0; i<n; i++)
		 Sum[j] += matr[i][j];
   }
}

// Вывод одномерного массива в общем виде
void print_arr(int arr[], int len)
  { int i;
	cout << "Is Array:\n";
	for (i=0; i<len; i++)
       cout << arr[i] << " " ;
	cout << endl;
  }

// Получение матрицы - динамический массив.
//Возвращает указатель и способ разбиения на строки.
int ** get_matr (int & n, int & m)
{
int	**a;
int i,j;
cout << "Input Rows, Columns\n";
cin >> n >> m;
a = new int * [n];       // Для массива строк
if (a == NULL)
{  cout << "\nNo memory\n";
   return NULL;         // Из функции
}
for (i = 0; i < n; i++)
{  a[i] = new int [m];  // Для каждой строки
     if (a[i] == NULL) {
	cout <<"\nNo memory\n";
	return NULL;        // Из функции
}
}
//cout << "Input matrix A(" << n << "," << m << ")"<< endl;
//for (i = 0; i < n; i++)
//   for (j = 0; j < m; j++)
//	  cin >> a[i][j];
return a;    // Адрес динамической памяти
}

// Вывод массива.
void print_matr_din (int **mas, int n, int m)     // Константное выражение
{  int i,j;
   for (i=0;i<n;i++)
	  {
	  for(j=0;j<m;j++)
		 cout << mas[i][j] << " " ;   //*(mas+i*m+j));
	  cout << endl;
	  }
}

// Функции и двумерные масивы.
// Передача в функцию строки матрицы как одномерного массива.
// Использование функций преобразования одномерного массива
// для работы со строками матрицы.

void print_matr_Rows(int matr[][M], int n, int m)
{
   for (int i=0; i<n; i++)
	  print_arr (matr[i],m);
}
//  В одномерном массиве наименьший элемент переставить вперед.
void Change (int arr[], int len)
{  
	int *ip;
	int *min= arr;
	for (ip= arr; ip<arr +len; ip++)
	  if (*ip<*min)
		 min=ip;
	// Перестановка
	*ip = *min;
	*min =*arr;
	*arr = *ip;
}


