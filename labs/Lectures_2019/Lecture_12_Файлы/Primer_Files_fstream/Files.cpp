#pragma once
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include "Files.h"
using namespace std;
//---------------------------------------------------------------------------
 /*������ ������� �� �����.
  ����� ������� ����� ���� ���������� ��� �����.
  ������ � ��������� ����� "data.txt". ��� �� ���������. */
#define  LEN_MAX 10

int main(void)
{
setlocale(LC_ALL, ".1251");
cout << "������, ���!" << endl;

ofstream F_out; 	// ��� ������� ������.
F_out.open("World.txt");	// �������� �����.��
   F_out << "������, ���!" << endl;
F_out.close();		// �������� �����.


string World;
cin >> World;

ifstream F_in; 	// ��� ������� ������.
F_in.open("World.txt");	// �������� �����.
F_in >>  World;
F_in.close();		// �������� �����.
// �����: ������ ������ - �� ������� ����������� �������.
// �����: getline(������, ����): getline(cin, World); getline(F_in, World);

// ������ 1. ����� ������� � ��������� ����.
int   Arr[LEN_MAX] = {1,2,3,4,5};
int   len=5;

Print_arr(Arr,len);			// �� �������.

// ����� � ��������� ����
string Name = "Data.txt";
Print_arr(Name, Arr,len);	// � ���� Data.txt.


// ������ 2. ���� ������� �� ���������� �����.
Input_arr(Arr, len);		// �� �������
Print_arr(Arr, len);

Input_arr("In_data.txt", Arr, len);		// �� ����� In_data.txt. len ������������ ��� �����.
Print_arr(Arr, len);

// ������ 3. ������(������) ����� �� ���������� �����.
string Text[10];
int ls = 0;
Input_text("Text.txt", Text, ls);

}









//  ���������:
//	char *fgets(char *s, int n,  FILE *stream);
//	int fputs  (const char *s,   FILE *stream);

