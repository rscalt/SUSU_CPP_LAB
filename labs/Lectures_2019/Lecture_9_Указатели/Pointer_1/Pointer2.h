#include    <stdlib.h>
#include    <iostream>

#define MAX_SIZE 10
using namespace std;
//---------------------------------------------------------------------------
//������������ ������.
//---------------------------------------------------------------------------
void Dymamic_memory_new(void)
{
int    * Arr;        // ��������� �� ������
int    i, Nn;         // Nn - �����
int    * ip;         // ��� ���������
cout << "\nInput Count of elements\n ";
   cin >> Nn;
Arr = new int[Nn];  // ��������� ������ ��� �������
if (Arr == NULL)
   {
	cout <<"\nMemory is Empty";
	return;
   }
//��������� �� �������
cout << "Input %d elements " << Nn;
for (i = 0; i < Nn; i++)
    cin >> Arr[i];
cout << endl;
//��������� �� ���������
cout <<"Is elements\n";
for (ip = Arr; ip < Arr+Nn; ip++)
	cout << *ip << " ";
//������������� ������
	delete  []Arr ;
}

//---------------------------------------------------------------------------
void Size(void)
{
 long	l;
 int    i;
 float  f;
 double d;
 int   m1[4];
 double m2[4];
//l = coreleft();
// printf("\n�������� ����= %ld", l);
cout << "\n The Byte of int\t"		<< sizeof(i);
cout << "\n The Byte of float \t"	<< sizeof(f);
cout << "\n The Byte of double\t"	<< sizeof(d);
cout << "\n The Byte of int array\t"	<< sizeof(int)*4;
cout << "\n The Byte of double array\t" << sizeof(double)*4;
cout << "\n The Byte of double array\t" << sizeof(m2);
}
//-----------------------------------------------------------------------------------
// ���������.
void print_Arr(int Arr[], int len)        // ����� ������� � ����� ����
  { int i;
	cout << "Is array:\n";
    for (i=0;i<len;i++)
       cout << Arr[i] << " ";
	cout << endl;
  }
void input_Arr(int *Arr,int &len)        // ����� ���������� - �����
  {                                      // ����� � ������������ ������
    int *ip;
	cout << "Input Count < " << MAX_SIZE;
	cin >> len;
	cout <<"Input elements\n";
    for (ip=Arr;ip<Arr+len;ip++)
       cin >> *ip;                   
  }
void transform_Arr(int *Arr, int len)    /*����� �� ���������� -  ��������*/
  { int i;
    for (i=0;i<len;i++)
       Arr[i]=Arr[i]*2;
  }
//---------------------------------------------------------------------------
// ������� ���������� ���������.
  int * new_Arr (int n)
  {
  int * Arr;	// ������� ��, ��������� � ����������.
	int * ip;
    Arr = new int [n];	   // �������� �����.
	 cout << "Input %d elements: " << n;
     for ( ip = Arr; ip < Arr+n; ip++)
	   cin >> *ip;
    return Arr;		// ������� ������.
  }

// ������� �������� �������.
  float F1(float x)
  {
	  return x + 1;
  }
  float F2(float x)
  {
	  return x*x;
  }
  void Table(float x0, float xn, float dx, float F(float x))
  {
	  for (float x = x0; x <= xn; x += dx)
		  std::cout << x << " " << F(x) << std::endl;
  }

