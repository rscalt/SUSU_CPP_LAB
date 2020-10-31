/* ��������� ���������� ����� ���������� � ��������� �������  (��������):
 */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <math.h>
#include <string.h>

typedef struct
{
  char	Name[20];           // ���: ������ char.
  int	Word;				// ����� �� ���������.
  int	Excel;
  int	Access;
  int	Sum;                // ����������� � ��������� ����� ������.
  double	Avg;            // ��������� � ��������� ������� ����������.
} Person;   		        // ��� ���� ������� "Person"


// ���� ������ �� ����� ������� ============================
void In(Person & Man)         // ���������� ������ ���� Person
{
   puts ("������� ���: ");
   scanf("%s",&Man.Name);
   puts ("������� ������: ");
   Man.Sum=0;                   // ����� ��������� ����� �����������.
   scanf_s ("%4d",&Man.Word);
   scanf_s("%4d", &Man.Excel);
   scanf_s("%4d", &Man.Access);
   Man.Sum+=Man.Word+Man.Excel+Man.Access;
   Man.Avg=(float) Man.Sum /3.;  // �������� ������� ����������.
}

// ����� ������ �� ����� �������=================================
void Out(Person Man)             // ���������� ������ ���� Person
{
   printf("%s ", Man.Name);
   printf ("%4d %4d %4d ",Man.Word,Man.Excel,Man.Access);  // ��������� ����� �������.
   printf("\n����� ������: %d  ",Man.Sum);
   printf("�������: %6.2f\n",Man.Avg);
}

// ����� ������ ��� ���� �������� � ����� �������============
void Out_All(Person Man[], int n)  // ���������� n ������ ���� Person
{
   printf ("===========================================\n");
   printf ("��� \t  \t  ������  \t  C����  �������\n");
   printf ("===========================================\n");
   for (int k=0;k<n;k++)
   {
   printf ("%10s %4d %4d %4d ", Man[k].Name,Man[k].Word,Man[k].Excel,Man[k].Access);  // ��������� ����� �������.
   printf("%4d ",Man[k].Sum);
   printf("%6.2f \n",Man[k].Avg);
   }
   printf ("====================================================\n");
}

// ��������� ������� ���������� �� ���� ��������==================
float Sred(Person Man[], int n)  // ���������� n ������ ���� Person
{
   float Avg=0;                 // Var �� ����� ��������� � ����� �������� � ������ Var.
   for (int i=0;i<n;i++)
      Avg+=Man[i].Avg;
   return Avg/(float) n;	//  ������� �� ���� �������.
}
// ��������� ������� ���������� ��  k-���� ��������: 1 - Word, 2 - Excell, 3 - Access. ==========
float Sred_k(Person Man[],int n, int k)  // ���������� n ������ ���� Person
{
   float Var_k=0;                // Var_k - ������� �� ������ ����������.
   switch (k)
   {
   case 1: {
	   for (int i=0; i<n; i++) // ���������� ���� ���������� �� ���� ��������.
		  Var_k += (float) Man[i].Word;
	   break;
		   }
   case 2: {
	   for (int i=0; i<n; i++) // ���������� ���� ���������� �� ���� ��������.
		  Var_k += (float) Man[i].Excel;
	   break;
		   }
   case 3: {
	   for (int i=0; i<n; i++) // ���������� ���� ���������� �� ���� ��������.
		  Var_k += (float) Man[i].Access;
	   break;
		   }
   } 
   return Var_k /(float) n;	//  ������� �� ������ ��������.
}

//// ���������� ����� ��������������������� �������================
//int Sred_Stat(Person Man[],int n)  // ���������� n ������ ���� Person
//{
//   float Var_All = Sred(Man,n);    // ������� ������� ���������� �� ���� ��������.
//   float Var_min = fabs(Var_All-Man[0].Avg);  // ���������� ����� ����� 0.
//   int Nom=0;
//   for (int i=0;i<n;i++)
//      if (fabs(Var_All-Man[i].Avg)<Var_min)
//	     Nom=i;                 // ���������� ����� ������ ��������.
//   return Nom;
//}
//
//// ���������� ��������� �� ��������� ������===================
//Person * Sred_Stat_k(Person Man[],int n,int k)  // ���������� n ������ ���� Person
//{
//   float Var_k = Sred_k(Man,n,k);    // ������� ������� ���������� �� ���� ��������.
//
//   float Var_min = fabs(Var_k-Man[0].Data[k]);  // ���������� ����� ����� 0.
//   Person * Nom = Man;	// ����� ����� �������� ��������.
//   for (int i=0;i<n;i++)
//      if ( fabs(Var_k-Man[i].Data[k])<Var_min)
//	     Nom=Man+i;                 // ���������� ����� ������ ��������.
//   return Nom;
//}

// ����� �� �������===================================
Person * Found_Fam(char *Who, Person Man[], int n)
{
   for (int i=0; i<n; i++)
       if (strcmp(Who,Man[i].Name)==0)       // ==0, ������ �������.
		return Man+i;
   return NULL;				       //���� ����� ��������.
}
