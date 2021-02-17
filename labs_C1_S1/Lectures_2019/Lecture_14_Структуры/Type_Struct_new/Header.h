/* ��������� ���������� ����� ���������� � ��������� �������  (��������): */
#include <iostream>
#include <io.h>
#include <math.h>
#include <string>
using namespace std;
typedef struct {
  string	Name;           // ���.
  int	Word;				// ����� �� ���������.
  int	Excel;
  int	Access;
  // int Balls[3];
  int	Sum;                // ����������� � ��������� ����� ������.
  double	Avg;            // ��������� � ��������� ������� ����������.
} Person;   		        // ��� ���� ������� "Person"

// ���� ������ �� ����� ������� ============================
void In(Person & Man)         // ���������� ������ ���� Person
{
   cout  << "������� ���: ";
   cin >> Man.Name;
   cout <<"������� ������: ";
   Man.Sum=0;                   // ����� ��������� ����� �����������.
   cout.flush();
        cin.ignore(256, '\n');
   cin >> Man.Word;
   cin>> Man.Excel;
   cin >> Man.Access;
   Man.Sum+=Man.Word+Man.Excel+Man.Access;
   Man.Avg=(float) Man.Sum /3.;  // �������� ������� ����������.
}

// ����� ������ �� ����� �������=================================
void Out(Person Man)             // ���������� ������ ���� Person
{
   cout << Man.Name << "\t" ;
   cout << Man.Word << "\t" << Man.Excel << "\t" << Man.Access << "\t" ;  // ��������� ����� �������.
   cout << Man.Sum << "\t"  << Man.Avg << endl;
}

// ����� ������ ��� ���� �������� � ����� �������============
void Out_All(Person Man[], int n)  // ���������� n ������ ���� Person
{
   cout <<"===========================================\n";
   cout << "��� \t    ������  \t  C����  �������\n";
   cout << "===========================================\n";
   for (int k=0;k<n;k++)
   {
   cout << Man[k].Name << "\t" << Man[k].Word << "\t" <<Man[k].Excel <<"\t" <<Man[k].Access ;  // ��������� ����� �������.
   cout << "\t " << Man[k].Sum << " \t" << Man[k].Avg << endl;
   }
   cout <<"====================================================\n";
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
   return Var_k /(float) n;	//  ������� �� k-���� ��������.
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
Person * Found_Fam(string  Who, Person Man[], int n)
{
   for (int i=0; i<n; i++)
       if (Who ==Man[i].Name)       // ==0, ������ �������.
		return Man+i;
   return NULL;				       //���� ����� ��������.
}
