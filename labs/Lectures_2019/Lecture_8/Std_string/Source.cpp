
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	char My_str[100];
	string str;
	cout << "Enter your name: ";
	getline(std::cin, str);
	// cin >> str;
	cout << "Hello, " << str << "!!! \n";
int Len = str.size();
	Len = str.length();
	//empty() - �����, ������������ true ��� ������ ������ � false ��� �������� :
	//bool B = str.empty();
	//�������� ��������� ����� == :
	string str_new("Petr");
	if (str == str_new) 
		// ���� �������
		cout << "Yes, " << str << "!!! \n";
	else 
		// ������ �������
		cout << "No, " << str << "!!! \n";
	std::string str1 = "Hello";
	std::string str2 = "World";
	std::string str3 = str1 + str2; // � ������ str3 : "HelloWorld".
	//������� c_str() ���������� ��������� �� ���������� ������, ������� �������� ������ ������� string :
	
	const char * strChar = str.c_str();
	
	//��������� � ��������� �������� ������ : �������� ����������[] ��� ����� at().
	std::string strS = "Hello World";
	cout << strS[7] << strS[0] << std::endl; // �� �������: oH
	//��� ������ at() ������, ��� �������� ������� :
	cout << strS.at(7) << strS.at(0) << std::endl; // �� �������: oH
	//����� at() ������������ �������� ������.
	int a = str.find('P',Len);
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
}
