
#include "Files.h"
//---------------------------------------------------------------------------

 /*Форматный обмен данных. Чтение массива из файла.
  Длина массива может быть определена при вводе.
  Массив в текстовом файле "data.txt". Там же результат. */
#include <stdio.h>
#include <conio.h>
#define  LEN_MAX 10

// =========Для двоичных файлов=======================
#include <io.h>
#include <fcntl.h>
//====================================================

int main(void)
{
// Пример 1. Чтение (запись) массива из текстового файла.
// Объявить файловую переменную:
FILE  * in_out;
// Открыть файл (fopen)

in_out = fopen("Data_1.txt", "wt");
// Проверить ошибки
if (in_out == NULL)
   {
	   perror("Ошибка входного файла.\n");
	   return 1;
   }

int   mas[LEN_MAX] = {1,2,3,4,5};
int   n=5;

Input_mas(mas,5);
	 Print_mas(mas,n);
// Вывод в текстовый файл
     Print_mas(in_out, mas,n);
   fclose (in_out); 

     getch();

// n будет определен при вводе
  in_out = fopen("Data_1.txt", "r");
  Input_mas(in_out,mas,n);






// Пример 2. Чтение (запись) матрицы из текстового файла.
 /*
	 int   m;
int   matr[10][10];
FILE  *in, *out;
in = fopen("Matrix.txt", "rt");
if (in == NULL)
   {
       perror("Ошибка входного файла.\n");
       return 1;
   }
if ((out = fopen("Matrix_new.txt", "wt")) == NULL)
   {
       perror("Ошибка выходного файла.\n");
       return 1;
   }
   Read_matr(in,matr,n,m);
   Print_matr(out,matr,n,m);


// Пример 3. Чтение (запись) строк из текстового файла.

getch();*/
// Пример 3. Чтение (запись) строк из текстового файла.
// Обмен и преобразование осуществляется построчно.
/*FILE *inS, *outS;
char *str=new char [100];
   if ((inS = fopen("prim_in.txt", "rt")) == NULL)
   {
	  printf("Ошибка открытия входного файла\n");
	  return 1;
   }

   if ((outS = fopen("prim_out.txt", "wt")) == NULL)
   {
	  printf("Ошибка открытия входного файла.\n");
	  return 1;
   }

int q ;
   while (!feof(inS))
   {
	fgets(str,100,inS);       // Наибольшая длина строки =100.
		printf("%s",str);     // Вывод на экран.
		str = Add_10(str);    // См. кодировки.
	fputs(str, outS);
   }

//  прототипы:
//	char *fgets(char *s, int n,  FILE *stream);
//	int fputs  (const char *s,   FILE *stream);


   fclose(inS);
   fclose(outS);*/
// Пример 4. Двоичные файлы - файлы прямого доступа.
// Функции fread, fwrite.

FILE	*in_B, *out_B;
int	Array [10];
int	len;
// Длина массива.
printf ("Input array. For quit -  Ctrl+Z\n");

len = 0;

while (!feof(stdin))			// Пока во входном потоке не встречен Ctrl+Z.
   scanf ("%d", &Array [len++]);
len--;
// Вывод массива на экран, то есть в поток stdout, это последовательный обмен.
Print_mas(Array,len);


// Вывод массива в двоичный файл прямого доступа, это прямой обмен.

int My_arr[10] = {1,2,3,4,5,6,7,8,9,100};
out_B = fopen("Out.bin", "wb");

fwrite(My_arr, sizeof(int), 10, out_B);
fclose (out_B);


in_B = fopen("Out.bin", "rb");
// Ввод массива из двоичного файла прямого доступа в новый массив.

int	Array_new [10];
fread (Array_new, sizeof (int), 10, in_B);
fclose (in_B);

Print_mas(Array_new,len);
getch();

}

/*
//  Пример 5. Ввод-вывод низкого уровня.
int  in_Block,out_Block;       //
int	Array [10];
int	len;
					// Длина массива.
printf ("Input Array <10 numbers. For exit = Ctrl+Z\n");
len = 0;
while (!feof (stdin))			// Пока во входном потоке не встречен Ctrl+Z.
	scanf ("%d", &mas [len ++]);
// Вывод массива на экран, то есть в поток stdout, это последовательный обмен.

for (int i = 0; i < len; i ++)
	printf ("%5d", mas [i]);

   out_Block = open ("Out_bl.bin", O_WRONLY|O_BINARY);
// Вывод массива в двоичный файл прямого доступа, это прямой обмен.
   write (out_Block, mas, sizeof (int)*len);
   close (out_Block);
   in_Block = open("Out_bl.bin", O_RDONLY);

// Ввод массива из двоичного файла прямого доступа в новый массив.
int	mas_new [10];
   read (in_Block, mas_new, sizeof (int)*len);
   close (in_Block);

for (int i = 0; i < len; i ++)
	printf ("%5d", mas_new [i]);
   getch();
   return 0;
	*/

