
#include <iostream>
#include <string>
#include <locale>
//#include <Windows.h>
//#include <clocale>
#include "My_string.h"
#include <fstream>
using namespace std;
int main()
{
	
// 	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	string R;
	cin >> R;
							  // ���� ��������.
	//Code();

	string Ss = F2("��� ��� ��� ������");
	cout << Ss << endl;
	string T("��� ��� ��� ������");
	F1(T);
	cout << T << endl;


	// ��-������:
	char My_str[100];

	// ��++ ������: ��������� ������ ���� string 
	string Name;

	//cout << "Enter your name: ";
	//getline(std::cin, Name);

	//// cin >> str;
	//cout << "Hello, " << Name << "!!! \n";
	
	
	// ���������� � ������������� �����: ���������� ����� - �����������.
	// ������ ������:
	string One;
	// ������ �������� ���������:
	string Two("��� ������\n");
	// ������, �������� ����� ������ ������:
	string Three(Two);
	

	// �������� �����:
	// ������ � ������� ������.
	int capacity = Name.size();
	int Len = Name.length();


	// ������ �����:
	// empty() - �����, ������������ true ��� ������ ������ � false ��� ��������.
	bool B = Name.empty();

	// ������������, �����������: ����������� �������� =.
	One = Two;     // ��������  Two � One.
	
	// ��� ������������ ����� ����������� �������� �������� + � �������� �������� � ������������� += :
	
	string str1 = "Hello";
	string str2 = "World!";
	
	string str3 = str1 + ", " + str2;   // � ������ str3 : "Hello, World".




	Name = "�������";
	// �������� ��������� �����:
	string str_new("����");
	if (Name == str_new)
		cout << "Yes, " << Name << "!!! \n";	 // ���� �������
	else
		cout << "No, " << Name << "!!! \n"; 	 // ������ �������
	
	// �������� ���������:
	//	== < > <= >= != ��������� ��������� � ������������������ �������.
	
	string foo = "����";
	string bar = "����";
	if (foo == bar) cout << "������ �����\n";
	if (foo != bar) cout << " ������ �� �����\n";
	if (foo< bar) cout << "������ ������\n"; 
	if (foo> bar) cout << "������ ������\n";

	// ����� compare.
	int Res = foo.compare(bar);
	cout << Res << endl;
	Res = bar.compare(foo);
	cout << Res << endl;

	// ������ � ��������� �������� ������ : �������� ����������[] ��� ����� at().
	string strS = "Hello, World!";
	
	cout << strS[7] << strS[0] << endl;     // �� �������: wh
	// ��� ������ at() ������, ��� �������� �������:
	
	cout << strS.at(7) << strS.at(0) << endl; // �� �������: wh
	
											  // ����� at() ������������ �������� ������.

	// ���������� �������� �� ������.
	// ������� c_str() ���������� ��������� �� ���������� ������, ������� �������� ������ ������� string :
	const char * strChar = Name.c_str();

	// �������������� �����
/*
append � ���������� ������ � ������;
assign� ��������� ���������� ������;
insert� ������� � ������;
erase� �������� ����� ������;
replace� ������ ����� ������.
*/

	string S = "������";
	cout << S << endl;
	
	S.append(" , ���������");
	
	cout << S << endl;
	
	S.assign("Hellow");
	
	cout << S << endl;

	S.insert(0, "�� ");

	cout << S << endl;

	S.erase(3, 3);

	cout << S << endl;

	S.replace(4,S.length(), "���-���-���");
	
	cout << S << endl;
// ����� � ������.
	// find � ������ ��������� � ������;
	// rfind � ��������� ��������� � ������;
	// find - first_of ������ ��������� �������  � ������;
	// find_last_of � ��������� ��������� �������  � ������;

	string Where("���, ���, ���, ������, ����, ����� ����� ��������.");
	int a = Where.find('P', Len);
	
	a = Where.find("���", 0);
	
	a = Where.find("���", Len);

// ����� ��������� ������ � ������
// ������� substr ���������� ��������� �������� ������, ������� � ������� 
// pos � ������� n ��������, ��� �� ����� ������.

	string Result = Where.substr(1, 3);

 // ������ �� �����
	ifstream F1("F1.txt");
	string Text;
	string Tmp;
	do
	{
	   getline(F1, Tmp);
	   Text.append(" ");
	   Text.append(Tmp);
	} while (!F1.eof());
	cout << Text;
	// ����� � ����

	ofstream out;				// out - ����� ��� ������.
	out.open("Hello.txt");  // ������� ���� ��� ������.
	if (out.is_open())
	{
		out << "Hello, World!" << endl;	// ��� ����������.
	}
	out.close();

		// ��� ��������� �� �����.
	Text = "��� ��� ��� ������ ���� rabbit go walk";
	string Words[100];
		int len = 0;
		Dictionary(Words, len, Text);

		remove_E(Text);

}
