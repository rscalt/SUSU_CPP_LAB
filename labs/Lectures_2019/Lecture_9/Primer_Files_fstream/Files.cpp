
#include "Files.h"
//---------------------------------------------------------------------------
 /*������ ������� �� �����.
  ����� ������� ����� ���� ���������� ��� �����.
  ������ � ��������� ����� "data.txt". ��� �� ���������. */
#define  LEN_MAX 10

int main(void)
{
// ������ 1. ����� ������� � ��������� ����.
int   Arr[LEN_MAX] = {1,2,3,4,5};
int   len=5;

Print_mas(Arr,len);			// �� �������.

// ����� � ��������� ����
string Name = "Data.txt";
Print_mas(Name, Arr,len);	// � ���� Data.txt.


// ������ 2. ���� ������� �� ���������� �����.
Input_mas(Arr, len);		// �� �������
Print_mas(Arr, len);

Input_mas("In_data.txt", Arr, len);		// �� ����� In_data.txt. len ������������ ��� �����.
Print_mas(Arr, len);

// ������ 3. ������(������) ����� �� ���������� �����.
string Text[10];
int ls = 0;
Input_text("Text.txt", Text, ls);

}









//  ���������:
//	char *fgets(char *s, int n,  FILE *stream);
//	int fputs  (const char *s,   FILE *stream);

