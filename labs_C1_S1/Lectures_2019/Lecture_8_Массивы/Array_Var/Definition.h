#include <stdio.h>

void Input(int a[], int &n)	     // !!!
{
   printf ("Введите длину <=100\n");
   scanf ("%d", &n);	// Определена в теле, возвращать - по ссылке.
   printf ("Введите элементы <=100\n");
   for (int i=0; i<n; i++)
      scanf ("%d", &a[i]);
}
void Del(int a[], int &n)
{
// Удалим четные значения
	for(int i=0; i<n; )
		if (a[i]%2==0)
			// Цикл удаления, длина уменьшилась.
		{
			for (int k=i; k<n-1; k++)
			   a[k]=a[k+1];
		    n--;
		}
		else 
			i++;
}