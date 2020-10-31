#pragma once
void F()
{
	int a;		    // 
	int A[100] = {1,2,66,77};		// Емкость.
	int len=4;		// <= Емкость.
	int *B;			// 4 байта, 
	B = new int[100];
	G(A, len);
	G(B, len);
	
	Copy(A, len, B);
	
	int *C = new int[10];
	C = Copy(A, len);

// как работать: прямая и косвенная
	for (int i = 0; i < len; i++)
	{	// B[i]
		// A[i]
	}
	for (int *i = A; i < A+len; i++)
	{	
		*i;		//  

	}


}

int G(int * A, int len)
{
	for (int i = 0; i < len; i++)
		A[i] = i;
}

int Copy(int A[], int len, int B[])
{
	for (int i = 0; i < len; i++)
		B[i] = A[i];
}
int * Copy(int A[], int len)
{
	int *B = new int[len];
	for (int i = 0; i < len; i++)
		B[i] = A[i];
	return B;
}