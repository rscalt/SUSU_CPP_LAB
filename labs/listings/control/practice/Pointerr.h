#pragma once
#include <iostream>
using namespace std;
#define MAX_SIZE 10
//---------------------------------------------------------------------------
//������������ ������.
//---------------------------------------------------------------------------
void Dynamic_memory_new(void)
{
	int    * Arr;        // ��������� �� ������
	int    i, Nn;        // Nn - �����
	int    * ip;         // ������� ���������� ��� ��������� ���������
	cout << "Input Count of elements\n";
	cin >> Nn;
	Arr = new int[Nn];  // ��������� ������ ��� �������
//��������� �� �������
	cout << "Input " << Nn << " elements\n";
	for (i = 0; i < Nn; i++)
		cin >> Arr[i];
		cout << endl;
//��������� �� ���������
	cout << "Is elements\n";
	for (ip = Arr; ip < Arr + Nn; ip++)
		cout << " " << *ip;
	cout << endl;
//������������� ������
	delete[]Arr;
}

//-----------------------------------------------------------------------------------
// ���������.
void Out_Arr_2(float Arr[], int len)        // ����� len �� ���������� - ��������.
{
	int i;
	cout.precision(3);
	cout << "Is array:\n";
	for (i = 0; i<len; i++)
		cout << "  " <<  Arr[i];
	cout << endl;;
}

void Input_Arr_2(float *Arr, int &len)        // ����� len ���������� - & �����.
{                                          
	float *ip; //����������-������
	cout << "Input Count < " << MAX_SIZE; //msize = 10 �� #define
	cin >> len;
	cout << "Input elements\n";
	for (ip = Arr; ip < Arr + len; ip++)
		cin >> *ip;                   
}

// Arr[i] = Arr[i] * 2
void transform_One(float Arr[], int len) 
{
	int i;
	for (i = 0; i<len; i++)
		Arr[i] = Arr[i] * 2;
}
// if (Arr[i] < 0) : (Arr[k] = Arr[k + 1], len--)
void transform_Two(float *Arr, int &len)
{
	int i;
	for (i = 0; i < len; i++)
		if (Arr[i] < 0)
		{
			for (int k = i; k < len - 1; k++)
				Arr[k] = Arr[k + 1];
			len--;
		}
}

//����������� ����� ���������
void Copy_One(float Arr[], float Arr_Copy[], int len)
{
	for (int i = 0; i < len; i++)
		Arr_Copy[i] = Arr[i]; //��������������� �����������
}

//return Arr_Copy as float*
float * Copy_Two(float Arr[], int len)
{
	float * Arr_Copy;	     // ������� ��, ��������� � ����������.
	Arr_Copy = new float[len];    //	�������� �����.
	for (int i = 0; i < len; i++)
		Arr_Copy[i] = Arr[i];
	return Arr_Copy;
}

//======================================================================
//��������� 3 - ������ twoArr()
float* twoArr
(float *mix_arr, int size, 
 float *two_arr_ptr, 
 int& positive_counter, //�� ������
 int& negative_counter) //�� ������

{ 	//����� ���������� ������ ����� ���������� ���������� ������������� � ������������� �������� (��� �����!)
	for (int i = 0; i < size; i++)
	{
		if (mix_arr[i] != 0) //������� �������� ������������
		{
			if (mix_arr[i] < 0)
				negative_counter++;
			else
			if (mix_arr[i] > 0)
				positive_counter++;
			else continue;
		}
	else continue;
	}
	//�������� ������ ��� ����� ������ (�������)
	two_arr_ptr = new float[positive_counter+negative_counter]();

	
	int delta_pos = 0;
	int delta_neg = 0;

	for (int i = 0; i < size; i++)
	{
		if (mix_arr[i] != 0) 
		{
			if (mix_arr[i] < 0)
			{	//positive_counter - �������� ��� ����������� ��������� ������� ������� (-)
				two_arr_ptr[positive_counter+delta_neg] = mix_arr[i];
				delta_neg++;
			}
			if (mix_arr[i] > 0) 
			{
				two_arr_ptr[delta_pos] = mix_arr[i];
				delta_pos++; 
			}
		}
		else continue;
	}
	return two_arr_ptr; //��������� �� ������ ������� �� ���� ��������
	//������� ����������: ������ �� ����� ����������� ����� ����������� ������ ��������� (&arr[0]) � ���������������� ����� ������� ����������� ���������� ������
}


//��� ���������� �4 - ������� ������ �������������� �������
int *new_arr(const unsigned int size)
{
    int *new_arr = new int[size]();
    for (int i = 0; i < size; i++)
    {
        if ((i+1)%2 == 0) 
             new_arr[i] = -(i+1)/2;
        else new_arr[i] =  (i+2)/2;
    }
    return new_arr;
}




