//---------------------------------------------------------------------------
#include "Module.h"
#include <stdio.h>
#include <conio.h>
#define N 10
//---------------------------------------------------------------------------

int main(void)
{
// �������� ������ - ������ ���� + ������� ������.
char Names [N][20];    // ������ ����.
int Balls [N][4];      // ����� ������- 4 c������.
int n;   		       // ����� �����
char Lesson [4][12]={"MS Word","MS Excel","MS Access","�����"};
// ����� ������ ��������� �����, ����� ��������� (���������).
// �������� ������ - ��� �������� ����������.
// ���� ����.
FILE *names;
names = fopen("Names.txt","wt");
FILE * Res;
int key;
do
{
	printf("Select point of nenu:\n");
	printf("1-Input names\n");  // ������ � ������� � ���������.
	printf("2-Input balls\n");
	printf("3-Output results\n");
	printf("4-Output Best\n");
	// ...
	printf("8-Exit\n");
	scanf("%d",&key);
	switch (key)
	{
// ���� ���� � ���������� � ��������� ����� Names.txt.
	case 1: { Input_name(names,Names,n); break;}
// ���� ������ ������� ��������� � ���������� � �������� ����� Balls.bin.
	case 2: {
			fclose (names);
			names = fopen("D:\\Work\\���-I\\Lectures_2013\\Modul_Style\\Primer_Modul_Style\\Names.txt","rt");
			//D:\Work\���-I\Lectures_2013\Modul_Style\Primer_Modul_Style
			Res= fopen("Balls.bin","wb");
			Input_balls(names, Res, Names, Balls, n);
            fclose(Res);
			break;
			}
// ����� ����������� �� Balls.bin �� �������.
	case 3: { 
		    Res= fopen("Balls.bin","rb");
		    Output(Res, Names, Balls, n, Lesson);
            fclose(Res);
			break;
			}
// ���������� �������� � ����� �� �������.
// 1 ������� - ����������� � ��������� � �����.
// 2 ������� - ����������� ������� � ��.
	case 4: { 
		    
		    ;
			break;
			}
	//...
	case 8: { return 1;}
	default: { return 1;}
		;
	}
}while (key!=8);
getch();

}
