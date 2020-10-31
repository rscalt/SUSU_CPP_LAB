/* Функция с несколькими параметрами. Варианты обращения */
#include <stdio.h>
float  sum_3 (float a, float b, float c)
{
   return a + b + c;
}

main()
{
float   a;
float	x, y, z;

x = 1;
y = 2;
z = 3;

   a = sum_3 (x, y, z);
   printf("\n%f", a);                  /*обращение в присваивании*/
   /*или*/
   printf ("\n%f", sum_3(4.,5.,6.));       /*обращение в выражении*/
}
