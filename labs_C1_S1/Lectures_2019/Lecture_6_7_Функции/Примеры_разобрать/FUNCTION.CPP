#include <stdio.h>
#include "function.hpp"

float Avg(float,float,float);
void main(void)
{
  float x1=2.5,x2=7,x3=3.5;
  float y=Avg(x1,x2,x3);
  printf("x1=%f, x2=%f, x3=%f y= %f\n" ,x1,x2,x3,y);
  y = Avg(2.,4.,7.);
  printf("x1=%f, x2=%f, x3=%f y= %f\n" ,2.,4.,7.,y);
  print();
  print(10);
  print(15,'=');
  int a=5,b=10;
  printf("a=%d b=%d\n",a,b);

  Swap1(a,b);
  printf("a=%d b=%d\n",a,b);

  Swap2(a,b);
  printf("a=%d b=%d\n",a,b);
}