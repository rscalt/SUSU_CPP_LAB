#pragma once
#include <iostream>

//���� 1. �������, ������������ ��������� �� ������.
//���������� 1. ��������� �� ������
//����� ������� Swap1 � ����������� �� ��������.
void Swap1(int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;	// ���������� ������������ ������ ����������.
}
//����� ������� Swap2 � ����������� �� ������.
void Swap2(int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;	// ���������� ������������ ������ ����������.
}

// ���������� 2. ������� ��� ��������������� ����������. 
// ������� ������� Range � ����� �����������, ������� ������ �������� 
// ���������� ���, ����� ��� ���� ����������� �� �����������. 
// ���������� � ���.
void Range(int &a, int &b, int &c)
{} //================================//��. ���� lab_06_1+2.cpp

// ���� 2. ������������� �������.
// ���������� 4. ���������� �������. 

void print(void)       
{
	int i;   // ��������� ����������.
	for (i = 1; i <= 50; i++)
	   std::cout << '*';
	std::cout << std::endl;
}
// ����������� ������� print(int n) � ����������, ������� ������� 
// �� ����� ��������� ����� �������� '*'. 
// ���������� � ��� 2-3 ���� � ������� ���������� ����������� ����������. 

void print(int n) //���������� �� ����� ��������
{
	for (int i = 1; i <= n; i++)
	std::cout << '*';
	std::cout << std::endl;
}

// ����������� ������� print(int n, char c) � ����� �����������, 
// ������� ������� �� ����� ��������� ����� ��������� ��������. 
// ���������� � ��� 2-3 ���� � ������� ���������� ����������� ����������. 

void print(int n, char symbol) //���������� �� ����� ��������
{	
	if(n > 80) n = 80;

	for (int i = 1; i <= n; i++)
		std::cout << symbol; 
	std::cout << std::endl;

}
// ���� 3. ������� �������� � ����� ����� ����.
// ���������� 4. ������������ �������� ������ ������������ ������� 
// ������� ��� �������. 
void Auto_f(void)
{
	int K = 1;
	std::cout << "\t K= "<< K << std::endl;
	K++;
}
void Stat_f(void)
{
	static int K = 1;
	std::cout << "\t K= "<< K << std::endl;
	K++;
}
// ���������� � ���.
//

// �����. 
// ������� �������, ��������� ����� ���� ������� ������, �������� ���������� 
// ���������� � ������������.



