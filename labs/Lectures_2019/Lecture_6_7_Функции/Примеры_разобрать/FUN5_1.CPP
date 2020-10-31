/*gun5.cpp*/
#include <stdio.h>                      /*Define - определенная функция*/
#include <math.h>
#define PI 3.1415926

void f(float x1, float x2, float dx)
{
float y;
for (float x=x1; x<=x2; x+=dx)
   {
    if (abs(x) <= 0.6)
       y = sin(x+PI/2);
       else
       y = cos(x+PI/2);
    printf("%5.2f %5.2f\n" ,x, y);
    }
}

void main(void)
{
float x1,x2,dx;
x1 = -PI/2.;
x2 = PI/2.;
dx = 0.3;
printf("Таблица значений \n  x      y     \n");
  f( x1,x2,dx);
printf("Таблица значений \n  x      y     \n");
  f( 0.,1.,0.1);
}


