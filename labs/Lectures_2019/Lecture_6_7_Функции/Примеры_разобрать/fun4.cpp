/*fun4.cpp*/
#include <stdio.h>        /*���⮥ �᫮*/
#include <conio.h>

int easy(int num)        /*�㭪�� �����頥� ���� ��� ��
			   �����᪮� ���祭��*/
{
   int ind, flag=0;
   for (ind=2; ind <= num/2; ind++)
       if (num%ind == 0)
	   flag=1;
   return(flag);
}
void main (void)
{
/*���ᨢ*/
int mas[5];
int ind;
printf("����� 5 �ᥫ");
  for(ind=0; ind<=4; ind++)
     scanf("%d",&mas[ind]);

  for(ind=0; ind<=4; ind++)
     {printf("%d",mas[ind]);
       if (easy(mas[ind])==1)
	  printf(" �� ���⮥\n");
	  else
	  printf(" ���⮥\n");
      }
}

