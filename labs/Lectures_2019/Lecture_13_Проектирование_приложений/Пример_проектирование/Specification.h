#pragma once
// ��������� ������.
// ������ � ������� �� ���������.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 10;	// ����� ����������.
// ������ ���������� �� �����. ����� ����������� � ���� � ������ File
void Input_names(string File, string Names[], int &n);
// ����� ������ ����.
void Print_names(string arr[], int len);  // len � ����� �������. 
// ������ ������ �� ���������� ������.
void Input_balls(string Names[], int Balls[][4], int &n);
// ��������� � ����� ������ ����������. 
// � ����� ������ ������ ����������� � ���� F_Names.
void File_Write(string F_Name, string Names[], int Balls[][4], int n);
// � ������ ������ ������ ������������ �� ����� F_Names.
void File_Read(string F_Name, string Names[], int Balls[][4], int n);
// 
void Swap(int &a, int &b);
void Swap(string &a, string &b);
// ���������� � ������� �������� ����� ������.
void Sort_Balls(string Names[], int Balls[][4], int n);
// ����� �� �����.
void Print(string Names[], int Balls[][4], int n);







