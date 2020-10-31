/*fun1.cpp*/
#include <stdio.h>

void print(int count, char C)                /*Описание функции без параметров*/
{                               /*выполняется до первого обращения к ней*/
int i;
for (i=1;i<=count; i++)
   printf("%c",C);
printf("\n");
}

void main()
{
  print(35,'#');
  printf("       Пример\n");
  print(44,'!');
}
