/* �����頥�� ���祭�� �㭪樨. ���� return.
�᫨ �㭪�� �����頥� ���� ���祭��, ��� �� ������ �१ return
*/

#include <stdio.h>
// ������� �᫮ � �⥯���.
// ��� ��ࠬ��� - �᭮����� - float, � �⥯���   - int */
#include <conio.h>
float pow_1 (float,int);      

void main()
{
int n;
float x;
clrscr();
   printf("������ ���. �᭮����� � 楫�� �⥯���\n");
   scanf ("%f%d",&x,&n);
   printf("\n\n\n����� � �襭��:%6.2f %4d %6.2f\n", x, n, pow_1(x,n));
   getch();
}

float pow_1(float x,int n)		// ���ᠭ�� �㭪樨 - �� ��ਠ�� ��室�.
{
float s;					// �����쭠� s 
if (n>0)
    { for(s=1.0; n>0; n--)
	  s *= x;
	return s;				// ��室
    }
						// 3 return - ࠢ���ࠢ�� ��室
    else
    if (n<0)
    { for(s=1.0; n<0; n++)
	  s*=x;
	return 1./s;
    }
    else
	return 1;				// ��� n=0

    printf ("���� �㦭� �� ���檨� �㭪樨"); // ����, � �����쭮�.
}

