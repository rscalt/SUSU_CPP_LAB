/* �㭪�� � ��᪮�쪨�� ��ࠬ��ࠬ�. ��ਠ��� ���饭�� */
#include <stdio.h>
float  sum_3 (float a, float b, float c)
{
   return a + b + c;
}

main()
{
float   a;
float	x, y, z;

x = 1;
y = 2;
z = 3;

   a = sum_3 (x, y, z);
   printf("\n%f", a);                  /*���饭�� � ��ᢠ������*/
   /*���*/
   printf ("\n%f", sum_3(4.,5.,6.));       /*���饭�� � ��ࠦ����*/
}
