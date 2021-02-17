 /*
Программа вычисляет значения корней квадратного уравнения.
Описание решения:
   1. Ввести значения коэффициентов (названы a,b,c).
   2. Вычислить дискриминант (назван d).
   3. Если дискриминант отрицательный, решения нет.
	Печать сообщения об этом.
   4. Если дискриминант > или =0, решение есть.
      Вычисляем значения корней и печатаем.
*/
#include   <stdio.h>
#include   <math.h>
void Primer_If_1 (void)
{
float a,b,c,d;
float x1,x2;
// 1.  Ввод значений
printf("\nInput coefficients.\n");
scanf("%f%f%f", &a,&b,&c);
// 2. Вычисление d
d=b*b-4*a*c;
// 3. Анализ
   if (d>=0.0)
   {
      x1=(-b+sqrt(d))/(2*a);           // 1-ая ветвь
      x2=(-b-sqrt(d))/(2*a);
	  printf("The roots is x1=%6.2f x2=%6.2f\n", x1,x2);
   }
   else
	printf("Is not Solusion\n");         // 2-ая ветвь
	getch();
} //end of Primer_If_1

/*Случай равных корней a=2 b=4 c=2 */
/*
Второй вариант. Случай равных корней можно предусмотреть.
В условном операторе появляется второе условие: d==0/
       if (d>0)
	   {
	      вычислить два корня
	   }
	   else
	   if (d==0)	// Проверка на точное равенство некорректна.
	      {
		   //вычислить один корень
	      }
	      else
		 {
		   //решения нет
		 }
*/

void  Primer_If_2 (void)
{
float a,b,c,d;
float x1,x2;
printf("\nInput coefficients.\n");
scanf("%f%f%f", &a,&b,&c);
d=b*b-4*a*c;
if (d >0.0)
   {
      x1=(-b+sqrt(d))/(2*a);
      x2=(-b-sqrt(d))/(2*a);
	  printf("The roots is x1=%16.13f x2=%16.13f\n", x1,x2);
   }
// d<=0
   else
      if ( d==0)    // Возможна ошибка!
	   {
	      x1=(-b+sqrt(d))/(2*a);
		  printf("The root is x1=x2=%16.13f\n",x1);
	   }
	  else      // d<0
	  printf("Is not Solusion\n");
	  getch();
}//end of Primer_If_2



