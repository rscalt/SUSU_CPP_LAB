#include <iostream>
using namespace std;
#include <math.h>
/*
���� ��� ����, Alpha � Beta.
�����: ���� ������� ����������� � ���� ����� ������.
� ����. ���� � ��������� �� ����.
*/
void main(void)
{
	int Alpha, Beta;	// ����.
	int A_B, gamma;		// 
	cout << "Input ��-�� � ��-��";
	cin >> Alpha >> Beta;
	// ���� ����� ������.
	if (Alpha > Beta)
		A_B = Alpha - Beta;
	else
		A_B = Beta - Alpha;
	gamma = (int) (Alpha + Beta)/2.0;
	cout << A_B << "  " << gamma << endl;
	system("pause");
}