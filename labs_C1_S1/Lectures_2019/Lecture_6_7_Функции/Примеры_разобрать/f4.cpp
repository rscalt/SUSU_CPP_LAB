/* Пример 4. Головная функция и 2 вызываемые функции без параметров */
#include <stdio.h>  					/* Описание функции printf */
#include <conio.h>               /* Описание функции getch  */

void f1(void)
{
printf("Функция 1\n");
}

void f2(void)
{
printf("Функция 2\n");
}

void main()
{
printf("\nГоловная функция main\n");
f1();
f2();
getch();
}
