#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
#include <clocale>
using namespace std;
void Code(void)
{
	int  i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{ // if (16*i+j >7 && 16*i+j<14) continue;
			cout << (char) (16 * i + j)<< " " ;     //���������� ������������� ��������� ����
		}
		cout << endl;
	}
}
// ������ 1. ������ �������������� ������.
// ������� ������ �� ������ ������ � ��������� �����. 
// �������� ������� - ������.
void F1(string T)
{
	int k = T.find_first_of(' ');
	T.erase(0, k);
	k = T.rfind(' ');
	T.erase(k);
}
// �������� ������� - ������. ������� �������� ����� ������.
string F2(const string T)
{
	string Tmp(T);
	int k = Tmp.find_first_of(' ');
	Tmp.erase(0, k);
	k = Tmp.rfind(' ');
	Tmp.erase(k);
	return Tmp;
}
// ������ 2. ������ ���������� �������� ������.
// ������ 5-� ������ �������� ������������ '!'. 
// �������� ������� - ������.
void remove_E(string &T)
{
	for (int i = 5; i < T.size(); i+=5)
		T.at(i) = '!';
}
// ������ 3. ���������� �����. 
// ������: �� ������ ������ �������� ������ - ������� ���� ���������� ������.
void Dictionary(string Words[], int &len, string Text)
{
	len = 0;
	int k = 0;
	string Word;
	Text.append(" ");
	do
	{
		k = Text.find_first_of(" ");
		if (k == -1) break;
		// �� ������ ������ �� ������� �������� � �������.
		Words[len++] = Text.substr(0, k);
		Text.erase(0, k + 1);		// �������� Text;
	} while (k != -1);
}

// ������ 4. ��������� �����.
// ����������� �� ����������� �����. 
// 1. �� ������ �������� ������.
// 2. �����������.
// 3. ������� � ������.
