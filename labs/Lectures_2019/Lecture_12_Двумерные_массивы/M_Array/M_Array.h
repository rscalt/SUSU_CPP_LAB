//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
const int N = 4;
const int M = 5;

using namespace std;
void print_matr(int matr[][M], int n, int m) //�����������! ����� ������-�����
{
int i,j;
cout << "Is Matrix\n";
	 for (i=0; i<n; i++)
		 {
			 for(j=0; j<m; j++)
			     cout << matr[i][j] << " " ;
		     cout << endl;
		 }
}
// ������������� ������� ������: ������� ������ � ����.
void print_matr(string File_name, int matr[][M], int n, int m) //�����������! ����� ������-�����
{
	ofstream out;				// out - ����� ��� ������.
	out.open(File_name);	    // ������� ���� ��� ������.
	if (out.is_open())
	{
		int i, j;
		out << "Is Matrix\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				out << matr[i][j] << " ";
			out << endl;
		}
		out.close();	// ����� ���������.
	}	// ����� ����� ������������� �� �������. 
}
// ������������� ������� �����: ������ ������ �� �����.
void input_matr(string File_name,int matr[][M], int &n, int &m)
{
	ifstream in;				// in - ����� ��� ������.
	in.open(File_name);	    // ������� ���� ��� ������.
	if (in.is_open())
	{
		int i, j;
		in >> n >> m;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				in >> matr[i][j];
	}// ����� ����� ������������� �� ���� � �������.
}
void input_matr(int matr[][M], int &n, int &m)
{
	int i, j;
	do {
		cout << "Input Rows & Columns " << N << M;
		cin >> n >> m;
	} while (n>5 || m>5);

	cout << "Input elements\n";
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
			cin >> matr[i][j];
}

/* ���������� � ���������� ������ � ���������� ��������� -.
��������� �����, ��� ����������� ���������  -
����� ������ �� �������,
� ������� �� ���������� ����� ��� ��������� �� �������.
��� �������� - �������� �� ��������.
*/

void Sum_Rows(int matr[][M], int n, int m, int Sum[])
{
   int i,j;
   for (i=0; i<n; i++)
   {
   Sum[i]=0;
	  for(j=0; j<m; j++)
		 Sum[i] += matr[i][j];
	  matr[i][m++] = Sum[i];
   }
}
void Sum_Columns(int matr[][M], int n, int m, int Sum[])
{
   int i,j;
   for (j=0; j<m; j++)
   {
   Sum[j]=0;
	  for(i=0; i<n; i++)
		 Sum[j] += matr[i][j];
   }
}

// ����� ����������� ������� � ����� ����
void print_arr(int arr[], int len)
  { int i;
	cout << "Is Array:\n";
	for (i=0; i<len; i++)
       cout << arr[i] << " " ;
	cout << endl;
  }

// ��������� ������� - ������������ ������.
//���������� ��������� � ������ ��������� �� ������.
int ** get_matr (int & n, int & m)
{
int	**a;
int i,j;
cout << "Input Rows, Columns\n";
cin >> n >> m;
a = new int * [n];       // ��� ������� �����
if (a == NULL)
{  cout << "\nNo memory\n";
   return NULL;         // �� �������
}
for (i = 0; i < n; i++)
{  a[i] = new int [m];  // ��� ������ ������
     if (a[i] == NULL) {
	cout <<"\nNo memory\n";
	return NULL;        // �� �������
}
}
//cout << "Input matrix A(" << n << "," << m << ")"<< endl;
//for (i = 0; i < n; i++)
//   for (j = 0; j < m; j++)
//	  cin >> a[i][j];
return a;    // ����� ������������ ������
}

// ����� �������.
void print_matr_din (int **mas, int n, int m)     // ����������� ���������
{  int i,j;
   for (i=0;i<n;i++)
	  {
	  for(j=0;j<m;j++)
		 cout << mas[i][j] << " " ;   //*(mas+i*m+j));
	  cout << endl;
	  }
}

// ������� � ��������� ������.
// �������� � ������� ������ ������� ��� ����������� �������.
// ������������� ������� �������������� ����������� �������
// ��� ������ �� �������� �������.

void print_matr_Rows(int matr[][M], int n, int m)
{
   for (int i=0; i<n; i++)
	  print_arr (matr[i],m);
}
//  � ���������� ������� ���������� ������� ����������� ������.
void Change (int arr[], int len)
{  
	int *ip;
	int *min= arr;
	for (ip= arr; ip<arr +len; ip++)
	  if (*ip<*min)
		 min=ip;
	// ������������
	*ip = *min;
	*min =*arr;
	*arr = *ip;
}


