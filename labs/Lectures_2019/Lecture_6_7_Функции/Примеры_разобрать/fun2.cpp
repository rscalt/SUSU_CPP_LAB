/*fun2.cpp*/
#include <stdio.h>
#include <conio.h>
void print(int count)                 /*���ᠭ�� �㭪樨 � ��ࠬ��஬*/
{                                     /*����� ��ப� ��६����� �����*/
int i;
for (i=1; i<=count; i++)              /*count -���-�� ᨬ����� � ��ப�*/
   printf("%c",'*');
printf("\n");
}

void main()
{
int count;
clrscr();
for (count=1; count<=12; count++)
  print(count);    /* �unt-⥪�饥 ��-��� ���-�� ᨬ����� � ��ப�*/
getch();
}






