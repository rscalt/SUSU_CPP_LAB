#include "Header.h"
#include <string.h>
#include <locale>

void main (void)
{ 
setlocale (LC_ALL,".1251"); 
char S[4] = {',','.','-'};
string H("Onee, two. tgree, bla-bla");
int Where = H.find(S, 80);

Person Man = {
	" ����� �������",5,4,3
};

   Person *Student = new Person;

   Person Man_copy;
   
   Man_copy = Man;

// ����� ��������.
   *Student = Man;
// ��������� �������� ����� �������.   
   Student = &Man;
   Out(Man);

//cout << Man.Name << " " << Man.Word << " " << Man.Excel << " " <<Man.Access<< endl;
//cout << Student->Name << " " <<Student->Word << " " <<Student->Excel << " " <<Student->Access << endl;

   int n;
   Person All_Person[20];
   cout << "������� ����������\n";
   cin >> n;
   
   for (int i=0;i<n;i++)
     In (All_Person[i]);

   Out_All(All_Person,n);

   string Find_name;	// ���� �������, �� �� ��, ��� � Person.
   cout <<"������� ������ ��� ������\n";
   cin >> Find_name;
   Person * Who;
   Who = Found_Fam(Find_name,All_Person,n);
   if(Who != NULL)
       Out(*Who);
       else
       cout <<"������ ���.\n";

}
