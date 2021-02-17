/*fun4.cpp*/
#include <stdio.h>        /*простое число*/
#include <conio.h>

int easy(int num)        /*функция возвращает одно как бы
			   логическое значение*/
{
   int ind, flag=0;
   for (ind=2; ind <= num/2; ind++)
       if (num%ind == 0)
	   flag=1;
   return(flag);
}
void main (void)
{
/*массив*/
int mas[5];
int ind;
printf("Введи 5 чисел");
  for(ind=0; ind<=4; ind++)
     scanf("%d",&mas[ind]);

  for(ind=0; ind<=4; ind++)
     {printf("%d",mas[ind]);
       if (easy(mas[ind])==1)
	  printf(" не простое\n");
	  else
	  printf(" простое\n");
      }
}

