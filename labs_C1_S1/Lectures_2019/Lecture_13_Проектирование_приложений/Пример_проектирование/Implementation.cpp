#include "Specification.h"
// Запись слушателей на курсы.
void Input_names(string File, string Names[], int &n)
{
	int i = 0;
	cout << "Сколько?: ";
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
// Вывод списка имен
void Print_names(string arr[], int len)  // len – длина массива. 
{
	int  i;
	cout << "Список слушателей:\n";      // Вывод заголовка. 
	for (i = 0; i < len; i++)
		cout << arr[i] << endl;         // Вывод имени в строку. 
}
// Запись баллов по завершении курсов.
void Input_balls(string Names[], int Balls[][4], int &n)
{	// Имена  = Names. Показываем  по одному и требуем ввести оценки
	for (int i = 0; i<n; i++)
	{
		cout << "Input balls for \t" << Names[i] << " ";
		cin >> Balls[i][0] >> Balls[i][1] >> Balls[i][2];
		Balls[i][3] = Balls[i][0] + Balls[i][1] + Balls[i][2];
	}
}
// Сохраняем в файле полную информацию. 
// В конце работы данные выгружаются в файл.
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

// В начале работы данные подгружаются из файла.
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

