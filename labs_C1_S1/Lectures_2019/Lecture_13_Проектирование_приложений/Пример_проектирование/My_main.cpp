#include "Specification.h"
#include <iostream>
#include <locale>
// ��� ������� ������� �������.
// ��� ��������� ��������� ������ ����������.
// ����� ��������� ������, ������� ����� ����������, � 
// �������� �� � ��������� � ������������ �� ��������� ������.
void main(void)
{
	setlocale(LC_ALL, ".1251");
// �������� ������.	
	string Names[N]; 	// ������ ����.
	int Balls[N][4];	// ������ ������ � �����.
	int Count = N;
	
	int Key;
	do
	{
		cout << "������ ����� ����\n";
		cout << "1. ������ �� ����: ������ ����� ����������\n";
		cout << "2. ������� ������ ����������\n";
		cout << "3. ��������� ������\n";
		cout << "4. �����������\n";
		cout << "5. ��������\n";
		cout << "6. �������\n";
		cout << "7. ��������\n";
		cout << "8. ��������� � ����\n";
		cout << "10. ����� \n";
		cin >> Key;
		switch (Key)
		{
		case 1: {Input_names("",Names,Count); break; }
		case 2: {Print_names(Names,Count); break; }
		case 3: {Input_balls(Names, Balls,Count); break; }
		case 4: {
			Sort_Balls(Names, Balls, Count);
			Print(Names, Balls, Count);
			break; }
		case 5: {Print(Names, Balls, Count); break; }
		case 6: {; break; }
		case 7: {; break; }
		case 8: {File_Write("Data.txt", Names, Balls, Count); break; }
		case 10: {return; }
		default: {; break; }
		}
	} while (Key != 10);
}




