 /*
��������� ��������� �������� ������ ����������� ���������.
�������� �������:
   1. ������ �������� ������������� (������� a,b,c).
   2. ��������� ������������ (������ d).
   3. ���� ������������ �������������, ������� ���.
	������ ��������� �� ����.
   4. ���� ������������ > ��� =0, ������� ����.
      ��������� �������� ������ � ��������.
*/
#include   <stdio.h>
#include   <math.h>
void Primer_If_1 (void)
{
float a,b,c,d;
float x1,x2;
// 1.  ���� ��������
printf("\nInput coefficients.\n");
scanf("%f%f%f", &a,&b,&c);
// 2. ���������� d
d=b*b-4*a*c;
// 3. ������
   if (d>=0.0)
   {
      x1=(-b+sqrt(d))/(2*a);           // 1-�� �����
      x2=(-b-sqrt(d))/(2*a);
	  printf("The roots is x1=%6.2f x2=%6.2f\n", x1,x2);
   }
   else
	printf("Is not Solusion\n");         // 2-�� �����
	getch();
} //end of Primer_If_1

/*������ ������ ������ a=2 b=4 c=2 */
/*
������ �������. ������ ������ ������ ����� �������������.
� �������� ��������� ���������� ������ �������: d==0/
       if (d>0)
	   {
	      ��������� ��� �����
	   }
	   else
	   if (d==0)	// �������� �� ������ ��������� �����������.
	      {
		   //��������� ���� ������
	      }
	      else
		 {
		   //������� ���
		 }
*/

void  Primer_If_2 (void)
{
float a,b,c,d;
float x1,x2;
printf("\nInput coefficients.\n");
scanf("%f%f%f", &a,&b,&c);
d=b*b-4*a*c;
if (d >0.0)
   {
      x1=(-b+sqrt(d))/(2*a);
      x2=(-b-sqrt(d))/(2*a);
	  printf("The roots is x1=%16.13f x2=%16.13f\n", x1,x2);
   }
// d<=0
   else
      if ( d==0)    // �������� ������!
	   {
	      x1=(-b+sqrt(d))/(2*a);
		  printf("The root is x1=x2=%16.13f\n",x1);
	   }
	  else      // d<0
	  printf("Is not Solusion\n");
	  getch();
}//end of Primer_If_2



