#pragma once
#include "Module.h"
void Rand_Arr(int a[], int len_a)
{
	// ���������� �������. 
	// ������� rand() ���������� ��������������� ����� � ��������� ��
	// 0 to RAND_MAX (32767). 
	for (int i = 0; i < len_a; i++)
		a[i] = (double)rand() / (RAND_MAX + 1) * 50 - 25;
	// �������� -25 - +25 
}
void Print_Arr(int a[], int len_a)	     // ��� (int a, int b)
{ //����� �������
	cout << "\nIs Array:\n";
	for (int i = 0; i<len_a; i++)
		cout << " " << a[i];
	cout << endl;
}
void Print_Arr(float a[], int len_a)
{ //����� �������
	cout << "\nIs Array:\n";
	for (int i = 0; i<len_a; i++)
		cout << " " << a[i];
	cout << endl;
}
void Input_Arr(int a[], int & len_a)
{ //���� �������
	cout << "\nInput length of Array:\n";
	cin >> len_a;	// ������� ������.
	cout << "\nInput " << len_a << " elements of Array:\n";
	for (int i = 0; i<len_a; i++)
		cin >> a[i];
}
void Input_Arr(float a[], int &len_a)
{
	//���� �������
	cout << "\nInput length of Array:\n";
	cin >> len_a;	// ������� ������.
	cout << "\nInput " << len_a << " elements of Array:\n";
	for (int i = 0; i<len_a; i++)
		cin >> a[i];
}
// ������� ��������������.
float Avg(float a[], int len)
{
	float S = 0;
	// ������������ ���������
	for (int i = 0; i<len; i++)
		S += a[i];
	return  S / (float)len;
}
// ������� ������� ��������� ��������.
// 2. ���������.
// 3. �������� ��������.
// 1. ���������, ���������� ��.
bool YesUp(int a[], int n)
{ // ������, ��� ����������.
	for (int i = 0; i< n - 1; i++)
		if (a[i + 1] >= a[i])
			return 0;
	return 1;
}
int YesDown(int a[], int n)
{ // ������, ��� ����������.
	for (int i = 0; i<n - 1; i++)
		if (a[i + 1] <= a[i])
			return 0;
	return 1;
}
// 2. ��������.
int Min(int a[], int n)
{ 	// ����� �����������.
	int min = 0;
	for (int i = 1; i<n; i++)
		if (a[i] < a[min])
			min = i;
	return min;
}
// ��������� ����� �������: ��������, �������.
// ! �������� ������.
// 3. ��������. �������� �����������.
void Add(int a[], int  & n, int Q)
{
	if (n < LEN)
		a[n++] = Q;
}
int Del(int a[], int  &n)
{
	int del = Min(a, n);	// ����� �����������.
	if (del == n - 1)
		n--;
	else   // �����
	{
		for (int k = del; k<n - 1; k++)
			a[k] = a[k + 1];
		n--;
	}
	return 1;   // ���� ������� ��� ���. 
}
// ����� �����, �������� ��������� �� ������ ���������.
// ������� ������ �� �����.
int Point(float x[], float y[], int Count)
{
	int maxn = 0;
	float R = sqrt(x[0] * x[0] + y[0] * y[0]);
	for (int i = 1; i<Count; i++)
		if (sqrt(x[i] * x[i] + y[i] * y[i]) > R)
		{
			maxn = i;
			R = sqrt(x[i] * x[i] + y[i] * y[i]);
		}
	return maxn;
}
bool Yes(int a[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = i + 1; j < len; j++)
			if (a[i] == a[j]) return true;
	return false;
}
struct Stud
{
	std::string Name;
	std::string NickName;
	int Weigth;
	int Age;
};
// len = 5:    a[5] =new_el;  len++; 
bool Addd(int a[], int & len, int new_el)
{
	// ������ ������� � �����.
	//if (len < LEN)
	//{
	//	a[len++] = new_el;
	//	return true;
	//}
	//return false;
	// �������� � ����������� �������: 44
	// 11, 22, 55, 99
	// ����� ������ ������� � ����� �������.
	// Insert
	int insert = len;
	for (int i = 0; i < len - 1; i++)
		if (new_el > a[i] && new_el < a[i + 1])
			insert = i + 1;
	// ���� ������ �������, ������ ����������.
	for (int k = len; k > insert; k--)
		a[k] = a[k - 1];
	a[insert] = new_el;
	len++;
	return true;
}



