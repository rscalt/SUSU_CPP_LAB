//---------------------------------------------------------------------------
#include <stdio.h>
#define N 5
#define M 5

void print_matr(int mas[][M], int n, int m) //Особенность! длина строки-число
{
int i,j;
printf ("Is Matrix\n");
	 for (i=0; i<n; i++)
		 {
			 for(j=0; j<m; j++)
			     printf("%5d", mas[i][j]);
		     printf("\n");
		 }
}
void input_matr(int mas[][M], int &n, int &m)
{
   int i,j;
   do
   {
	  printf("Input Rows <=%d & Columns <=%d\n",N,M);
	  scanf("%d%d",&n,&m);
   }while (n>5 || m>5);
   printf("Input elements\n");
   for (i=0; i<n; i++)
	  for(j=0; j<m; j++)
		 scanf("%d", & mas[i][j]);
}


/* Управление в алгоритмах работы с двумерными массивами -.
вложенные циклы, где управляющая переменая  -
номер строки во внешнем,
и столбца во внутреннем цикле для просмотра по строкам.
Или наоборот - просмотр по столбцам.
*/

void Sum_Rows(int mas[][M], int n, int m, int Sum[])
{
   int i,j;
   for (i=0; i<n; i++)
   {
   Sum[i]=0;
	  for(j=0; j<m; j++)
		 Sum[i] += mas[i][j];
   }
}
void Sum_Columns(int mas[][M], int n, int m, int Sum[])
{
   int i,j;
   for (j=0; j<m; j++)
   {
   Sum[j]=0;
	  for(i=0; i<n; i++)
		 Sum[j] += mas[i][j];
   }
}

// Вывод массива в общем виде
void print_mas(int mas[], int len)

  { int i;
	printf("Is Array:\n");
	for (i=0; i<len; i++)
       printf("%5d",mas[i]);
	printf("\n");
  }


// Получение матрицы - динамический массив.
//Возвращает указатель и способ разбиения на строки.

int ** get_matr (int & n, int & m)
{
int	**a;
int i,j;
printf ("Input Rows, Columns\n");
scanf("%d%d", &n,&m);

a = new int * [n];       // Для массива строк
if (a == NULL)
{  printf("\n No memory\n");
   return NULL;         // Из функции
}
for (i = 0; i < n; i++)
{  a[i] = new int [m];  // Для каждой строки
     if (a[i] == NULL) {
	printf("\nNo memory");
	return NULL;        // Из функции
}
}
printf ("Input matrix A(%d,%d)", n, m);
for (i = 0; i < n; i++)
   for (j = 0; j < m; j++)
	  scanf("%d", &a[i][j]);
return a;    // Адрес динамической памяти
}

// Вывод массива.
void print_matr_din (int **mas, int n, int m)     // Константное выражение
{  int i,j;
   for (i=0;i<n;i++)
	  {
	  for(j=0;j<m;j++)
		 printf("%5d", mas[i][j]);//*(mas+i*m+j));
	  printf("\n");
	  }
}

// Функции и двумерные масивы.
// Передача в функцию строки матрицы как одномерного массива.
// Использование функций преобразования одномерного массива
// для работы со строками матрицы.

void print_matr_1(int mas[][M], int n, int m)
{
   for (int i=0; i<n; i++)
	  print_mas (mas[i],m);
}

void Change (int mas[], int len)
{   //Наименьший элемент переставим вперед
	int *ip;
	int *min=mas;
	for (ip=mas; ip<mas+len; ip++)
	  if (*ip<*min)
		 min=ip;
	// Перестановка
	*ip = *min;
	*min =*mas;
	*mas = *ip;
}


