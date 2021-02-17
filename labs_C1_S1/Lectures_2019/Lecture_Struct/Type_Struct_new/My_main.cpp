#include "Header.h"
#include <string.h>
#include <locale>

void main (void)
{ 
setlocale (LC_ALL,".1251"); 
    
Person Man = {
	" Фродо Беггинз",5,4,3
};
   Person *Student = new Person;
   Person Man_copy;
   Man_copy = Man;

// Копия значения.
   *Student = Man;

   // Указатель получает адрес объекта.   
   Student = &Man;

   printf("%s %d %d %d\n", Man.Name, Man.Word, Man.Excel, Man.Access);
   printf("%s %d %d %d\n", Student->Name, Student->Word, Student->Excel, Student->Access);
   //if (strstr(Man.Name > Student->Name)		// в лексикографический порядок.
	  // printf("Yes\n");
   //else
   //    printf("Yes\n");


   int n;
   Person All_Person[20];

   printf("Введите количество\n");
   scanf_s("%d",&n);

   for (int i=0;i<n;i++)
     In (All_Person[i]);
 
   Out_All(All_Person,n);

   char Find_name[20];	// Тоже фамилия, но не та, что в Person.
   puts ("Введите строку для поиска\n");
   fflush(stdin);
   gets(Find_name);      //
   Person * Who;
   Who = Found_Fam(Find_name,All_Person,n);
   if(Who!=NULL)
       Out(*Who);
       else
       puts("Такого нет.\n");

}
