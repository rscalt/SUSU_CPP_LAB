
#include "Files.h"
//---------------------------------------------------------------------------

 /*��������� ����� ������. ������ ������� �� �����.
  ����� ������� ����� ���� ���������� ��� �����.
  ������ � ��������� ����� "data.txt". ��� �� ���������. */
#include <stdio.h>
#include <conio.h>
#define  LEN_MAX 10

// =========��� �������� ������=======================
#include <io.h>
#include <fcntl.h>
//====================================================

int main(void)
{
// ������ 1. ������ (������) ������� �� ���������� �����.
// �������� �������� ����������:
FILE  * in_out;
// ������� ���� (fopen)

in_out = fopen("Data_1.txt", "wt");
// ��������� ������
if (in_out == NULL)
   {
	   perror("������ �������� �����.\n");
	   return 1;
   }

int   mas[LEN_MAX] = {1,2,3,4,5};
int   n=5;

Input_mas(mas,5);
	 Print_mas(mas,n);
// ����� � ��������� ����
     Print_mas(in_out, mas,n);
   fclose (in_out); 

     getch();

// n ����� ��������� ��� �����
  in_out = fopen("Data_1.txt", "r");
  Input_mas(in_out,mas,n);






// ������ 2. ������ (������) ������� �� ���������� �����.
 /*
	 int   m;
int   matr[10][10];
FILE  *in, *out;
in = fopen("Matrix.txt", "rt");
if (in == NULL)
   {
       perror("������ �������� �����.\n");
       return 1;
   }
if ((out = fopen("Matrix_new.txt", "wt")) == NULL)
   {
       perror("������ ��������� �����.\n");
       return 1;
   }
   Read_matr(in,matr,n,m);
   Print_matr(out,matr,n,m);


// ������ 3. ������ (������) ����� �� ���������� �����.

getch();*/
// ������ 3. ������ (������) ����� �� ���������� �����.
// ����� � �������������� �������������� ���������.
/*FILE *inS, *outS;
char *str=new char [100];
   if ((inS = fopen("prim_in.txt", "rt")) == NULL)
   {
	  printf("������ �������� �������� �����\n");
	  return 1;
   }

   if ((outS = fopen("prim_out.txt", "wt")) == NULL)
   {
	  printf("������ �������� �������� �����.\n");
	  return 1;
   }

int q ;
   while (!feof(inS))
   {
	fgets(str,100,inS);       // ���������� ����� ������ =100.
		printf("%s",str);     // ����� �� �����.
		str = Add_10(str);    // ��. ���������.
	fputs(str, outS);
   }

//  ���������:
//	char *fgets(char *s, int n,  FILE *stream);
//	int fputs  (const char *s,   FILE *stream);


   fclose(inS);
   fclose(outS);*/
// ������ 4. �������� ����� - ����� ������� �������.
// ������� fread, fwrite.

FILE	*in_B, *out_B;
int	Array [10];
int	len;
// ����� �������.
printf ("Input array. For quit -  Ctrl+Z\n");

len = 0;

while (!feof(stdin))			// ���� �� ������� ������ �� �������� Ctrl+Z.
   scanf ("%d", &Array [len++]);
len--;
// ����� ������� �� �����, �� ���� � ����� stdout, ��� ���������������� �����.
Print_mas(Array,len);


// ����� ������� � �������� ���� ������� �������, ��� ������ �����.

int My_arr[10] = {1,2,3,4,5,6,7,8,9,100};
out_B = fopen("Out.bin", "wb");

fwrite(My_arr, sizeof(int), 10, out_B);
fclose (out_B);


in_B = fopen("Out.bin", "rb");
// ���� ������� �� ��������� ����� ������� ������� � ����� ������.

int	Array_new [10];
fread (Array_new, sizeof (int), 10, in_B);
fclose (in_B);

Print_mas(Array_new,len);
getch();

}

/*
//  ������ 5. ����-����� ������� ������.
int  in_Block,out_Block;       //
int	Array [10];
int	len;
					// ����� �������.
printf ("Input Array <10 numbers. For exit = Ctrl+Z\n");
len = 0;
while (!feof (stdin))			// ���� �� ������� ������ �� �������� Ctrl+Z.
	scanf ("%d", &mas [len ++]);
// ����� ������� �� �����, �� ���� � ����� stdout, ��� ���������������� �����.

for (int i = 0; i < len; i ++)
	printf ("%5d", mas [i]);

   out_Block = open ("Out_bl.bin", O_WRONLY|O_BINARY);
// ����� ������� � �������� ���� ������� �������, ��� ������ �����.
   write (out_Block, mas, sizeof (int)*len);
   close (out_Block);
   in_Block = open("Out_bl.bin", O_RDONLY);

// ���� ������� �� ��������� ����� ������� ������� � ����� ������.
int	mas_new [10];
   read (in_Block, mas_new, sizeof (int)*len);
   close (in_Block);

for (int i = 0; i < len; i ++)
	printf ("%5d", mas_new [i]);
   getch();
   return 0;
	*/

