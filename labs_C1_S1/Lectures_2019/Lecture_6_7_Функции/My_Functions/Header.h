#pragma once
#include <math.h>
#include <iostream>

//���� 1. �������, ������������ ��������� �� ������.
//������ - ���������� �������� ����������.

//����� ������� Swap1 � ����������� �� ��������.
void Swap1(int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// ���������� ������������ ������ ����������.
}
//����� ������� Swap2 � ����������� �� ������.
void Swap2(int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;		// ���������� ������������ ������ ����������.
}

// ���� 1. ��������� �� ������. 
// ������ �������, ������������ �������� � ������� ������������.
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

// ���� 2. ������������� �������.
#include <stdio.h>
void print(void)       
{
	int i;                   // ��������� ����������.
	for (i = 1; i <= 50; i++)
		printf("%c", '*');
	printf("\n");
}


   // ������������� �������.
   // ���������� �� ����� ����������.
   // ���� ���, ���������� ����� ����������.
   // ������: ����� ���������� �� ���������� �����.
   // int    max (int, int);
   // int    max (int, int, int);


int max(int x, int y)
{
	return x>y ? x : y;
}

int    max(int x, int y, int z)
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

int Triangle(float a, float b, float c, float & p, float &s)
/*�������� ������� - ��� �������� ������ */
{
	float pp;  //������������.
	if (a + b <= c || a + c <= b || b + c <= a)
		return 0;
	else
	{
		p = a + b + c;
		pp = p / 2.;
		s = sqrt(pp*(pp - a)*(pp - b)*(pp - c));
		return 1;
	}
}
