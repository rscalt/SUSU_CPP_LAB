/*fun1.cpp*/
#include <stdio.h>

void print(int count, char C)                /*���ᠭ�� �㭪樨 ��� ��ࠬ��஢*/
{                               /*�믮������ �� ��ࢮ�� ���饭�� � ���*/
int i;
for (i=1;i<=count; i++)
   printf("%c",C);
printf("\n");
}

void main()
{
  print(35,'#');
  printf("       �ਬ��\n");
  print(44,'!');
}
