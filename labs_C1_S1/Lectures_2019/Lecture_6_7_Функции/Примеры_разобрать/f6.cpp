/* возвращаемые значения функции. Роль return.
Если функция возвращает одно значение, она это делает через return
*/

#include <stdio.h>
// Возвести число в степень.
// Два параметра - Основание - float, и степень   - int */
#include <conio.h>
float pow_1 (float,int);      

void main()
{
int n;
float x;
clrscr();
   printf("Введите вещ. основание и целую степень\n");
   scanf ("%f%d",&x,&n);
   printf("\n\n\nДанные и решение:%6.2f %4d %6.2f\n", x, n, pow_1(x,n));
   getch();
}

float pow_1(float x,int n)		// Описание функции - три варианта выхода.
{
float s;					// Локальная s 
if (n>0)
    { for(s=1.0; n>0; n--)
	  s *= x;
	return s;				// Выход
    }
						// 3 return - равноправный выход
    else
    if (n<0)
    { for(s=1.0; n<0; n++)
	  s*=x;
	return 1./s;
    }
    else
	return 1;				// для n=0

    printf ("кому нужны эти дурацкие функции"); // Кстати, о локальном.
}

