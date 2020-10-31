#include <math.h>
/*
ѕреобразование и приведение типов в выражени€х.
*/

void main(void)
{
float x,y=(float)1;		// y= 1.0
x = sin(3.14*y+1);	    // 1->1.0

int a=3 ,b=7.6;

x = a / b;
x = (float) a / (float) b;

x = 4;
y = pow (x,  1./2  );	// 


}