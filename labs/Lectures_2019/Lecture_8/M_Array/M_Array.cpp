//---------------------------------------------------------------------------
#include "M_Array.h"
//---------------------------------------------------------------------------
#include <conio.h>
#include <stdio.h>
#define N 4
#define M 5
void main(void)
{
int i,j;
	 int n,m;
	 int matr[N][M];
/*  	 printf("Input Rows, Columns\n");
	 scanf("%d%d",&n,&m);
	 printf("Input_elements\n");
	 for (i=0;i<n;i++)
	    for(j=0;j<m;j++)
		  scanf("%d", &matr[i][j]);
	 printf("Is matrix\n");
	 for (i=0;i<n;i++)
	 {
		 for(j=0;j<m;j++)
		    printf("%d   ", *(&matr[0][0]+i*M+j));
printf("\n");
	 }
	 int a[5]={1,2,3,4,5};
for (i=0;i<5;i++)
    printf("%d   ", *(a+i));
*/
/*
//���� ������� - ��������� ����� �����, ��������.
input_matr(matr,n,m);
//����� �������  - �������. ����������� ��� �������� ����������.
print_matr(matr,n,m);
//���������� ������ - ������ �������

for (int i=0;i<n;i++)
	Change (matr[i],m);
for (int i=0;i<n;i++)
    print_mas(matr[i],m);
*/
/*
int Sum[N];
Sum_Rows(matr,n,m,Sum);
// ����� �� �������
print_mas(Sum,n);

Sum_Columns(matr,n,m,Sum);
// ����� �� ��������
print_mas(Sum,m);
*/
//������������ ��������� ������
int nd, md;
int ** D_matr;
//������� ��������� ������ ��� �������
//� ����� ��������. ��������� �� ������.
D_matr = get_matr(nd,md);
//����� �������  - �������. ����������� ��� �������� ����������.
print_matr_din(D_matr,nd,md);

//����� �������  - �������. ����������� ��� �������� ����������.
print_matr_din(D_matr,nd,md);
getch();
}
