#include "Header.h"
#include <locale>

void main (void)
{ 
setlocale (LC_ALL,".1251"); 	
   int n;
   Person All_Person[20];
   printf("������� ����������\n");
   scanf("%d",&n);
   for (int i=0;i<n;i++)
     In (All_Person[i]);
    Out_All(All_Person,n);
   int Found = Sred_Stat(All_Person,n);
   printf("����� ������� ����� �����: %d\n", Found);
   printf("��� ������: \n");
   Out (All_Person[Found]);
   // ����� ������� ������� �� �����.
   Out_All(All_Person,n);
   Person *Found_k;
   for (int k=0;k<5;k++)
   {
      printf("������� �� %d -�� ����������\n",k);
      Found_k = Sred_Stat_k(All_Person,n,k);
      Out(*Found_k);
   }
   char Surname[20];	// ���� �������, �� �� ��, ��� � Person.
   puts ("������� ������ ��� ������\n");
   scanf("%s",Surname);      //
   Person * Who;
   Who = Found_Fam(Surname,All_Person,n);
   if(Who!=NULL)
       Out(*Who);
       else
       puts("������ ���.\n");
}
