/*fun2.cpp*/
#include <stdio.h>
#include <conio.h>
void print(int count)                 /*Описание функции с параметром*/
{                                     /*печать строки переменной длины*/
int i;
for (i=1; i<=count; i++)              /*count -кол-во символов в строке*/
   printf("%c",'*');
printf("\n");
}

void main()
{
int count;
clrscr();
for (count=1; count<=12; count++)
  print(count);    /* соunt-текущее зн-ние кол-ва символов в строке*/
getch();
}






