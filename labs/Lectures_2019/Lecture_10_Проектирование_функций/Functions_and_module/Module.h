#pragma once
#include <conio.h>
#include <stdlib.h>
#include <time.h>  // ��� srand()
#include <iostream>
#include <locale>
using namespace std;
using namespace std;
const int LEN = 100;
// ���������� ������� ���������� �������. 
void Rand_Arr(int a[], int len_a);
//����� �������
void Print_Arr(int a[], int len_a);	 
void Print_Arr(float a[], int len_a);
void Input_Arr(int a[], int & len_a);
void Input_Arr(float a[], int &len_a);
// ������� ��������������.
float Avg(float a[], int len);
// ������� ������� ��������� ��������.
// 1. ���������, ���������� ��.
bool YesUp(int a[], int n);
int YesDown(int a[], int n);
// 2. ��������.
int Min(int a[], int n);
// ��������� ����� �������: ��������, �������.
// ! �������� ������.
// 3. ��������. �������� �����������.
void Add(int a[], int  & n, int Q);
// ��� �������? 
int Del(int a[], int  &n);
// �������� � ������, 
bool Addd(int a[], int & len, int new_el);


