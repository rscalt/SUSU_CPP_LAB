#include <stdio.h>

void Input(int a[], int &n)	     // !!!
{
   printf ("������� ����� <=100\n");
   scanf ("%d", &n);	// ���������� � ����, ���������� - �� ������.
   printf ("������� �������� <=100\n");
   for (int i=0; i<n; i++)
      scanf ("%d", &a[i]);
}
void Del(int a[], int &n)
{
// ������ ������ ��������
	for(int i=0; i<n; )
		if (a[i]%2==0)
			// ���� ��������, ����� �����������.
		{
			for (int k=i; k<n-1; k++)
			   a[k]=a[k+1];
		    n--;
		}
		else 
			i++;
}