// Самый простой пример. Функция описана перед main
// pow (x,2.)

#include <stdio.h>
float sqr(float x)
{
   return x*x;
}


void main(void)
{
float  a, b;
	a = 2;
	b = sqr (a);
	printf("\n%f", b);
	printf("\n%f", sqr(a));
}

