#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include "Table.h"
using namespace std;
void main(void)
{//	Table(1., 0.57);
	
	//double Money0;
 //   do
	//{
	//	printf("Input Money0\n");
	//	cin >> Money0;
	//	Boy_and_Ancle(Money0);
	//	cout << "Press any key...\n";
	//} while (_getch( ) != 27);	// Enter=13, Ecs=27/


	// ���������� ����� ����� ������������ ����.
	// S = 1 + 2 + 3 + 4 +...+ n	n - ���-�� ��������.
	// S = 1, S = S+2, S = S+3, S = S+i - ���. ����������.
	// While
	int n, S = 0;  // n-����� ���������, � �����, � �������� ����������
	printf("\nInput N\n");
	scanf("%d", &n);

	int i = 0;	// ����������
	S = 0;
	while (i <= n)	// ��������.
	{
		S += i;   // S=0, S=S+1, S=S+2,
		i++;
	}
	printf("Summa = %d\n", S);
	// Do..While
	printf("\nInput N\n");
	scanf("%d", &n);
	S = 0; i = 1;   // ����������
	do
		S += i++;   // 
	while (i<=n);
	
	printf("Summa =  %d\n", S);
	// 1. �������� ���������
	//Table(2.,0.3);
	// 2. �������� ����������
	double a=3, f=0.1;
	//Table(a, f);
	
	
	
	// 3. ��������� � �����.
	const double pi = 3.14;
	const double Delta_x = pi / 12;
	double xx;
	double y;
	printf("\tx\t y\n");
	for (xx = 0; xx <= pi; xx += Delta_x)
		{
			y = sin(xx);	
			printf("x=%12.2f y=%12.2f\n", xx, y);
		}
	// F1();

// For
 printf("\nInput N\n");
 scanf("%d", &n);
 for (int i=1,S=0;i<=n;i++)
	S += i;                // ���� �� �����.
 printf("Summa = %d\n", S);

// ����������� ���������� �� ����������� ������ ����.
float S1,x;
for (x=1.,S1=0.; x<=2.0; x*=1.1)
   S1+=x;
 printf("Summa= %6.3f", S1);
// Break
// ����� ����� �������������� ����������,
// �� ����������� ���������� �������� N.
printf("\nInput N\n");
scanf("%d", &n);
S=0;
 i;
for (i=1; ;i++)
 {                                         // ����������� ����
	S+=i;
	if (S>n)      break;                 // ������� ����������
 }
printf("Count of elements %d\n", i);
// Continue
 for (S1=0,x=-0.5; x<=1.1; x+=0.1)       // ��� x=0 - ������� �� 0.
 {
	 if (fabs(x) < 0.0001) continue;    //���� � ����������� 0
	 S1 += 1./x;
 }
 printf("Summa= %6.3f", S1);

getch();
}