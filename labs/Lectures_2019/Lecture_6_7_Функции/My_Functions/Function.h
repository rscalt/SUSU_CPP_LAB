#include <math.h>
#include <iostream>
using namespace std;
// 
// ���� 1. �������, ������������ ��������.
// ����� ���, ����� ���, // ����� ������ ����������.
// ������� ������� ������� �������������� 
// ���� �����.

float Avg(float a, float b, float c)
{
	float T = (a + b + c) / 3.;
	return T;	// ��� ��������� � ����� �������.
}

// void �������
void Table(double x0, double xn, int count)
{
	double y;
	double delta = (xn - x0) / (double) count;
	cout <<  " x= " << " y=" << endl;
	for (double x = x0; x<xn; x+=delta)
	{
		y = sin(x);
		cout << x << " " << y << endl;
	}
}


// ����� ����� ������������ ����.
int Summ(int n)
{
	int S = 0;
	for (int k = 1; k <= n; k++)
		S += k;
	return S;
}
// ����� ��� �������� ���������� ������������ �����.
void Del (int n)
{
	for (int k = 2; k <= n / 2; k++)
		if (n%k == 0)
			std::cout << "K=" << k << std::endl;
}




// ��������� �� ������. 
// ����� �������� � ������� ������������.
bool Square(float a, float b, float c, float  &p, float &s)
{
	p = (a + b + c);
	float pp = p*0.5;
	if (a + b > c && b + c > a && b + c > a)
	{
		s = sqrt(pp*(pp - a)*(pp - c)*(pp - b));
		return true;
	}
	else
	{
		s = p = 0;
		return false;
	}
}

// ���� 2. ������� ���� void.
// ������������� �������.

#include <stdio.h>
void print (void)        // ������� ���� void ��� ����������.
{
int i;                   // ��������� ����������.
for (i = 1; i <= 50; i++)
   printf("%c",'*');
printf("\n");
}
void print (int n)                // ������� ���� void ��� ����������.
{
int i;                          // ��������� ����������.
for (i=1; i <=n ; i++)
   printf("%c",'*');
printf("\n");
}
void print(char c)                // ������� ���� void ��� ����������.
{
	int i;                          // ��������� ����������.
	for (i = 1; i <= 50; i++)
		printf("%c", c);
	printf("\n");
}

void print (int n, char c)                // ������� ���� void ��� ����������.
{
int i;   // ��������� ����������.
if (n>80) 
	n=80;
for (int i=1;i<=n;i++)
   printf("%c",c);

printf("\n");
for (int i = 1; i <= n; i++)
printf("%c", c);
}


void print(int n, char c1, char c2)                // ������� ���� void ��� ����������.
{
	int i;   // ��������� ����������.
	if (n>80)
		n = 80;
	for (i = 1; i <= n; i++)
		printf("%c%c ", c1,c2);
	printf("\n");
}

//���� 3. �������, ������������ ���������.
//������ - ���������� �������� ����������.

//����� ������� Swap1 � ����������� �� ��������.
void Swap1 (int x, int y)
{ 	
	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// ���������� ������������ ������ ����������.
}

//����� ������� Swap2 � ����������� �� ������.
void Swap2 (int &x, int &y)
{ 	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// ���������� ������������ ������ ����������.
}

// ��������� �� �������� - ������ ������.
int Sum1 (int n)
{
int	S = 0;			// ���������� ��� ���������� �������� �����.
int	i; 			// ����������� ���������� ��� ����� ������������.
	for (i = 1; i<= n; i++)
		S += i;
return	S;
}
// � ���� ������� ��������� ���������� i �� ����������. ����, ��� ��������,
// ������������ �� ��������, �� ����� ������� ��������, ��� ����� ������������
// ��� ������� ���������� ��� ���������� ������.

int Sum2 (int n)
{
   int S;
	for ( S = 0; n > 0; n--)	// ��� n=0 ���� ����� ��������.
		S += n;
return	S;
}  // ������� �� ������� �������� n.


// ������������� �������.
// ���������� �� ����� ����������.
// ���� ���, ���������� ����� ����������.
// ������: ����� ���������� �� ���������� �����.
// int    max (int, int);
// int    max (int, int, int);


int max (int x, int y)
{
    return x>y ? x : y;
}

int    max (int x, int y, int z)
{
    return x>y ? (x>z ? x : z) : (y>z ? y : z);
}
int  max(int x[], int n)
{
	int max = 0;
	for (int i = 0; i < n; n++)
		if (x[max] > x[i])
			max = i;
	return max;
}


/* ������� ������� ������� � �������� ������������, ��������� ������� ������.
 ������������ �������� - ������� � ��������.
   ���� �������� ����� return,
   ��� ����� ���������. ��� ������������� �������� int. ����� - �������� ������� �������������.
   �������� = 1, ���� ����������� ����������, ����� 0, ���� ���.
*/

#include <math.h>

int Triangle(float a,float b, float c, float & p, float &s)
       /*�������� ������� - ��� �������� ������ */
{
float pp;  //������������.
if (a+b <=c || a+c<=b || b+c<=a)
    return 0;
    else
    {
    p=a+b+c;
    pp=p/2.;
    s=sqrt(pp*(pp-a)*(pp-b)*(pp-c));
    return 1;
    }
}
#include <conio.h>
/*
void My_window (void)
{
	 window(1,1,80,25);
     textbackground(WHITE);
     clrscr();
     textbackground(BLACK);
     window(15,5,65,20);
     clrscr();
     textbackground(CYAN);
     window(16,6,64,19);
	 clrscr();
getch();
}*/

