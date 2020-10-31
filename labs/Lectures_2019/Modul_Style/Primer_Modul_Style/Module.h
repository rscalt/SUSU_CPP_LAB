//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
// Функциональная декомпозиция -
// набор собственных функций программиста
// для решения типовых задач.

void Print_mas (int mas[], int len)  // len – длина массива. 
{ 
int  i;       // Рабочая переменная. 
 printf ("Массив:\n");    // Вывод заголовка. 
  for (i = 0;i < len; i++) 
  printf ("%5d",mas[i]);  // Вывод элемента массива в строку. 
 printf ("\n");
}
void Input_name(FILE *names, char Names[][20], int & n)
{
   int i=0;
   do
   {
	  printf ("Input name :");
      fflush(stdin);
	  gets(Names[i]);
	  i++;
   }while (!feof(stdin));

   n=i-1;	    //i-1?
   // Вывод
   for (i=0; i<n; i++)
   {
	  fprintf(names,"%s\n",Names[i]);
   }
   fflush(names);
}
// 
void Input_balls(FILE *names, FILE *result, char Names[][20], int Balls[][4], int &n)
{
// Читаем имена
int i;
// 1 - rewrite (файл должени быть открыт как w+ r+
// 2 - закрыть для записи и открыть для чтения
for (i=0;i<n;i++)
{
   fscanf (names,"%s",& Names[i]);
}
// Показываем  по одному и требуем ввести оценки
for (i=0;i<n;i++)
{
   printf ("Input balls for %s \t", Names[i]);
   scanf("%d%d%d", &Balls[i][0], &Balls[i][1], &Balls[i][2]);
   Balls[i][3] = Balls[i][0] + Balls[i][1] + Balls[i][2];
}
// Сохраняем.
for (i=0;i<n;i++)
{
	fwrite(Names[i],sizeof(Names[i]),1,result);
	fwrite(Balls[i],sizeof(Balls[i]),1,result);
}

}

void Output(FILE *result, char Names[][20], int Balls[][4], int n, char Lesson [3][12])
{
int i,j;
	for (i=0;i<n;i++)
{
	fread(Names[i],sizeof(Names[i]),1,result);
	fread(Balls[i],sizeof(Balls[i]),1,result);
}
	// Вывод названий как заголовков.
printf ("\t\t");
for (i=0;i<4;i++)
    printf ("%10s ",Lesson[i]);
printf("\n");
for (i=0;i<n;i++)
{
    printf ("%15s",Names[i]);
	for (j=0;j<4;j++)
       printf ("%10d ", Balls[i][j]);
	printf("\n");
}
}

