/*gun5.cpp*/
#include <stdio.h>                      /*Define - определенная функция*/
#include <math.h>
#define PI 3.1415926
float f(float x);
void main()
{
float x;
printf("Таблица значений \n  x      y     \n");
for (x=-PI/2.; x<=PI/2.; x+=0.2 )
    {
      printf("%5.2f %5.2f\n" ,x, f(x));
    }
}

float f(float x)
{
    if (abs(x)<=0.6)
       return
	  sin(x+PI/2);
       else
       return
	  cos(x+PI/2);
}

