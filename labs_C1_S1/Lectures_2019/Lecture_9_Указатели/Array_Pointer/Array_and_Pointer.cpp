
#include "Pointerr.h"
#define MAX_SIZE 10
void main(void)
{
	int A = 5;
	float a[MAX_SIZE];
	int n;
	Input_Arr(a, n);
	transform_One(a, n);
	Out_Arr(a, n);
	transform_Two(a, n);
	Out_Arr(a, n);
// new           delete
	float *Arr;
	Arr = new float[5];
	
	int len = sizeof(a) / sizeof(int); // Нетрудно догадаться, что len =5.
	
	Input_Arr(Arr, len);
	transform_One(Arr, len);
	Out_Arr(Arr, len);
	transform_Two(Arr, len);
	Out_Arr(Arr, len);

	float b[MAX_SIZE];
	Copy_One(a, b, 3);
	Out_Arr(b, 3);
    float *New_a = Copy_Two(a,3);
	Out_Arr(New_a, 3);
	system("pause");
}