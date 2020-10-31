/* Пример 5. Головная функция и 2 вызываемые функции без параметров */
#include <stdio.h>  					/* Описание функции printf */
#include <conio.h>               /* Описание функции getch  */

void f1(void);                 /* Прототип функции fun1 */
void f2(void);						/* Прототип функции fun2 */

void main()
{
printf("\nГоловная функция main\n");
f1();
f2();
getch();
}

void fun1(void)
{
printf("Функция 1\n");
}

void fun2(void)
{
printf("Функция 2\n");
}
