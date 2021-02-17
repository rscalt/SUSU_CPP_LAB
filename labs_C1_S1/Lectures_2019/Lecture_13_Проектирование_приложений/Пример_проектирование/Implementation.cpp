#include "Specification.h"
// ������ ���������� �� �����.
void Input_names(string File, string Names[], int &n)
{
	int i = 0;
	cout << "�������?: ";
	cin >> n;
	do
	{
		cout << "Input name: ";
		cin >> Names[i];
		i++;
	} while (i < n);                  // (!cin.eof());
	ofstream Out;
	Out.open(File);
	for (int i = 0; i < n; i++)
		Out << Names[i] << endl;
	Out.close();
}
// ����� ������ ����
void Print_names(string arr[], int len)  // len � ����� �������. 
{
	int  i;
	cout << "������ ����������:\n";      // ����� ���������. 
	for (i = 0; i < len; i++)
		cout << arr[i] << endl;         // ����� ����� � ������. 
}
// ������ ������ �� ���������� ������.
void Input_balls(string Names[], int Balls[][4], int &n)
{	// �����  = Names. ����������  �� ������ � ������� ������ ������
	for (int i = 0; i<n; i++)
	{
		cout << "Input balls for \t" << Names[i] << " ";
		cin >> Balls[i][0] >> Balls[i][1] >> Balls[i][2];
		Balls[i][3] = Balls[i][0] + Balls[i][1] + Balls[i][2];
	}
}
// ��������� � ����� ������ ����������. 
// � ����� ������ ������ ����������� � ����.
void File_Write(string F_Name, string Names[], int Balls[][4], int n)
{
	ofstream Out;
	Out.open(F_Name);
	for (int i = 0; i < n; i++)
	{
		Out << Names[i] << '\t';
		for (int j = 0; j < 4; j++)
			Out << Balls[i][j] << " ";
		Out << endl;
	}
	Out.close();
}

// � ������ ������ ������ ������������ �� �����.
void File_Read(string F_Name, string Names[], int Balls[][4], int n)
{
	ifstream In;
	In.open(F_Name);
	for (int i = 0; i < n; i++)
	{
		In >> Names[i];
		for (int j = 0; j < 4; j++)
			In >> Balls[i][j];
	}
	In.close();
}
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void Swap(string &a, string &b)
{
	string t = a;
	a = b;
	b = t;
}
void Swap(int a[], int b[], int len)
{
	for (int i = 0; i < len; i++)
		Swap(a[i], b[i]);
}
void Sort_Balls(string Names[], int Balls[][4], int n)
{
	int flag = 1;
	while (flag)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (Balls[i][3] > Balls[i + 1][3])
			{
				for (int j = 0; j < n; j++)
					Swap(Balls[i][j], Balls[i][j+1]);
				Swap(Names[i], Names[i + 1]);
				flag = 0;
			}

		}
	}
}
void Print(string Names[], int Balls[][4], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << Names[i] << '\t';
		for (int j = 0; j < 4; j++)
			cout << Balls[i][j] << " ";
		cout << endl;
	}
}

