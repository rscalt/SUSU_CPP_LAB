#pragma once
#include <math.h>
#include <iostream>
using namespace std;
// ���� 1. �������, ������������ ��������.
// ����� ���, ����� ���, ����� ������ ����������.
// ������� ������� ������� �������������� ���� �����.
// ���������� 1. ��������� � �������.

float Avg(float a, float b, float c)
{
	float T = (a + b + c) / 3.;

    cout << a << "\t";
    cout << b << "\t";
    cout << c << "\t";
    return T;
	 //����� ����������
  	// ��� ��������� � ����� �������.
	
}

// ���������� 2. �������� �������, ������ ������ ������� ������������ �� �������� ������ ������.
// float Square(float a, float b, float c)

//��. ���� area_heron ==========================

// ���������� 3. �������, �� ������������ ��������.
// ����� ���, ����� ���, ����� ������ ����������.
// ������ ������� �������� ������� y = sin(x)
// �� ������������ ��������� �������� �� x0 �� xn

void Table(double x0, double xn, int Count)
{
	double x, y;
	double Delta = (xn-x0) / (double) Count;
	for (x = x0; x <= xn; x += Delta)
	{
		y = sin(x);
		cout << "x=" << x << " y=" << y << endl;
	}
}

// ���������� 4. �������� �������, ������� ������ 
// ������� �������� ������� y = A*sin(fi*x) 
// �� ������������ ���������. ��� ��������, ��� ������  
// ���������� ����� �������� ����������� A, fi. 

void Table_A(double x0, double xn, int Count, double A, double fi)
{
	double x, y;
	double Delta = (fi*xn-x0) / (double) Count;

	for (x = x0; x <= fi*xn; x += Delta)
	{
		y = A*sin(fi*x);
		cout << "x_A=" << x << " y_A=" << y << endl;
	}
}
