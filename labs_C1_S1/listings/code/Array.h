#include <iostream>
#include <iomanip> 
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>  // ��� srand()

using namespace std;
//===================================================

void Rand_Arr(int a[], int len_a)
{
// ���������� �������. 
// ������� rand() ���������� ��������������� ����� � ��������� ��
// 0 to RAND_MAX (32767). 
for (int i = 0; i < len_a; i++)
	a[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // �������� -25 - +25 
}

void Rand_Arr(int a[], int b[], int len) //���������� ���� ������������ ��������
{

for (int i = 0; i < len; i++)
	{
		a[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
		b[i] = (double)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // �������� -25 - +25 
	}
}

void Rand_Arr(float a[], int len_a) //���������� ��� ������������ ��������
{
// ���������� �������. 
// ������� rand() ���������� ��������������� ����� � ��������� ��
// 0 to RAND_MAX (32767). 
for (int i = 0; i < len_a; i++)
	a[i] = (float)rand( ) / (RAND_MAX + 1) * 50 - 25;
	    // �������� -25 - +25 
}
//===================================================

void Print_Arr (int a[], int len_a)	     // ��� (int a, int b)
{ //����� �������
cout << "\nIs Array:\n";
for (int i=0; i<len_a; i++)
	cout << " " << a[i];
cout << endl;
}

void Print_Arr (float a[], int len_a)
{ //����� �������
	cout << "\nIs Array:\n";
	for (int i = 0; i<len_a; i++)
		cout << " " << a[i];
	cout << endl;
}
//===================================================

void Input_Arr(int a[], int &len_a)
{ //���� �������
   cout << "\nInput length of Array:\n";
   cin >> len_a;	// ������� ������.
   cout <<"\nInput " << len_a << " elements of Array:\n";
   for (int i=0; i<len_a; i++)
	  cin >> a[i];
	}

void Input_Arr(float a[], int &len_a)
{
//���� �������
	cout << "\nInput length of Array:\n";
	cin >> len_a;	// ������� ������.
	cout << "\nInput " << len_a << " elements of Array:\n";
	for (int i = 0; i<len_a; i++) //����� -1 ��
		cin >> a[i];
}
//===================================================

// ������� ��������������.
float Avg(float a[], int len)
{
float S=0;
// ������������ ���������
for (int i=0;i<len;i++)
	S+=a[i];
return  S / (float) len;
}

//===================================================

// ������� ������� ��������� ��������.
// 1. ���������, ���������� ��.
int YesUp(int a[], int n)
{ // ������, ��� ����������.
for (int i = 0; i< n - 1; i++)
	if (a[i + 1] >= a[i])
		return 0;
return 1;
}
int YesDown(int a[], int n)
{ // ������, ��� ����������.
	for (int i = 0; i< n - 1; i++)
		if (a[i + 1] <= a[i])
			return 0;
	return 1;
}

//===================================================

// 2. �������� ������� � ���������� ����� ����������� ��������.
	int Min(int a[], int n)
	{ 	// ����� �����������.
	int min=0;
	for (int i=1; i<n; i++)
		if (a[i]<a[min])
			min=i;
	return min;
	}

int Min(float a[], int n) //������� ���������� ��� float-�������
{ 	// ����� �����������.
int min = 0;
for (int i = 1; i<n; i++)
	if (a[i]<a[min])
		min=i;
return min;
}

int Max(float a[], int n) //������� ������� ������ ������� ������������� �������� float-�������
{ 	// ������ �����������
int max = n-1;
for (int i = max; i >= 0 ; i--)
	if (a[i] > a[max])
		max = i;
return max;
}

//===================================================

// ��������� ����� �������. ! �������� ������.
// 3. ��������. �������� ����������� �������� �������.
int Del(int a[], int  &n)
{
int del = Min(a,n);	// ����� �����������.
if (del==n-1)
	n--;
else   // �����
	{
	for (int k = del; k<n-1; k++)
      a[k] = a[k+1];
    n--;
    } 
return 1;   // ���� ������� ��� ���. 
}

int remove_farpoint(int x[], int y[], int  &n, int ind_far) //�������� ����� ������� ����� �������� ����� ��� ������������ �������
{
int del = ind_far;	// ������ ����� ������� ����� = ����� ������
if (del == n-1)
	n--; //������� ���������� ���������� !���������! ����� �������
else   // �����
	{
	for (int k = del; k < n-1; k++) //����� ������ ������� �����
      {
	  x[k] = x[k+1]; 
      y[k] = y[k+1]; 
	  }    
	  n--; //�������� ��������� �������, �.�. k = k+1
    } 
cout << " Point deleted sucessfully!";
return 1;   // ���� ������� ��� ���. 

}
//===================================================

// ������������ �������.
// ����� �����, �������� ��������� �� ������ ���������.
// ������� ������ �� �����.
int Point(int x[], int y[], int Count)
{
	int maxn = 0;
	float R = sqrt(x[0] * x[0] + y[0] * y[0]);

	for(int i=1; i<Count; i++)
		if (sqrt(x[i] * x[i] + y[i] * y[i]) > R)
		{
			maxn = i;
			R = sqrt(x[i] * x[i] + y[i] * y[i]);
			//cout << i << ". R is " << R << "\n";
		}
	return maxn;
}

//=============================================
// ��������� �������, � �.�. �� �����������

void print_array (float arr[], int arr_length) //���������� ����� float
{
        cout << "Array at " << arr << ":\n";

        cout << "index\t" << "element\t";
		cout << "hex_address\t" << "dec_address\n";
    for (int i = 0; i < arr_length; i++)
		{
        cout << setw(2) << i << "\t";
		cout << setw(5) << setprecision(2) << arr[i] << "\t";
		cout << setw(10) << &arr[i] << "\t";
		printf("%d",&arr[i]);
		cout << "\n";
		}
}

void print_array (int arr[], int arr_length) //���������� ����� int
{
        cout << "Array " << arr << ":\n";
		cout << "index\t" << "element\n";
    for (int i = 0; i < arr_length; i++)
        cout << setw(2) << i << "\t" << setw(5) << arr[i] << "\n";   
}

void print_array (int arr_a[], int arr_b[], int arr_length) //���������� ����� ���� ������������ int-��������
{
        cout << "\nArrays " << arr_a << " and " << arr_b << ":\n";
		cout << "index\t" << setw(6) << "x\t" << "y\n";
    for (int i = 0; i < arr_length; i++)
        {
			cout << setw(2) << i << "\t" << setw(5) 
			<< arr_a[i] << "  " << arr_b[i] << "\n";   
		}
}

void transform_array (float arr[], int arr_length) //������ ���������, ������� ������ �������� - ����� ������� ���������
{
    cout << "transform_array() initialized...\n";
    float arr_avg = Avg(arr, arr_length);
    for (int i = 0; i < arr_length; i++)
    {
        if (arr[i] > arr_avg) 
        {
            cout << arr[i] << " > "<< arr_avg << "; ";
            arr[i] = arr_avg;
            cout << "replacing arr["<< i << "] with average... \n"; //������ ��������������� �������� ������� ���������
        }
    }
    cout << "Done!\n\n";
}

//===================================================

struct Stud
{
	std::string Name;
	std::string NickName;
	int Weigth;
	int Age;
};



