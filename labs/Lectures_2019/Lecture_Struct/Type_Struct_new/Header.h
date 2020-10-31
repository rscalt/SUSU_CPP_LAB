/* Структура объединяет некую информацию о некотором объекте  (человеке):
 */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <math.h>
#include <string.h>

typedef struct
{
  char	Name[20];           // Имя: массив char.
  int	Word;				// Баллы по предметам.
  int	Excel;
  int	Access;
  int	Sum;                // Накапливает и сохраняет сумму баллов.
  double	Avg;            // Вычисляет и сохраняет средний показатель.
} Person;   		        // Имя типа данного "Person"


// Ввод данных об одном объекте ============================
void In(Person & Man)         // Передается данное типа Person
{
   puts ("Введите имя: ");
   scanf("%s",&Man.Name);
   puts ("Введите данные: ");
   Man.Sum=0;                   // Будет накоплена сумма показателей.
   scanf_s ("%4d",&Man.Word);
   scanf_s("%4d", &Man.Excel);
   scanf_s("%4d", &Man.Access);
   Man.Sum+=Man.Word+Man.Excel+Man.Access;
   Man.Avg=(float) Man.Sum /3.;  // Вычислен средний показатель.
}

// Вывод данных об одном объекте=================================
void Out(Person Man)             // Передается данное типа Person
{
   printf("%s ", Man.Name);
   printf ("%4d %4d %4d ",Man.Word,Man.Excel,Man.Access);  // Выводится одной строкой.
   printf("\nСумма баллов: %d  ",Man.Sum);
   printf("Среднее: %6.2f\n",Man.Avg);
}

// Вывод данных обо всех объектах в форме таблицы============
void Out_All(Person Man[], int n)  // Передается n данных типа Person
{
   printf ("===========================================\n");
   printf ("ИМЯ \t  \t  ДАННЫЕ  \t  CУММА  СРЕДНЕЕ\n");
   printf ("===========================================\n");
   for (int k=0;k<n;k++)
   {
   printf ("%10s %4d %4d %4d ", Man[k].Name,Man[k].Word,Man[k].Excel,Man[k].Access);  // Выводится одной строкой.
   printf("%4d ",Man[k].Sum);
   printf("%6.2f \n",Man[k].Avg);
   }
   printf ("====================================================\n");
}

// Вычисляет средний показатель по всем объектам==================
float Sred(Person Man[], int n)  // Передается n данных типа Person
{
   float Avg=0;                 // Var не имеет отношения к полям структур с именем Var.
   for (int i=0;i<n;i++)
      Avg+=Man[i].Avg;
   return Avg/(float) n;	//  Среднее по всем средним.
}
// Вычисляет средний показатель по  k-тому предмету: 1 - Word, 2 - Excell, 3 - Access. ==========
float Sred_k(Person Man[],int n, int k)  // Передается n данных типа Person
{
   float Var_k=0;                // Var_k - средний по одному показателю.
   switch (k)
   {
   case 1: {
	   for (int i=0; i<n; i++) // Складывает один показатель по всем объектам.
		  Var_k += (float) Man[i].Word;
	   break;
		   }
   case 2: {
	   for (int i=0; i<n; i++) // Складывает один показатель по всем объектам.
		  Var_k += (float) Man[i].Excel;
	   break;
		   }
   case 3: {
	   for (int i=0; i<n; i++) // Складывает один показатель по всем объектам.
		  Var_k += (float) Man[i].Access;
	   break;
		   }
   } 
   return Var_k /(float) n;	//  Среднее по одному предмету.
}

//// Определяет номер среднестатистического объекта================
//int Sred_Stat(Person Man[],int n)  // Передается n данных типа Person
//{
//   float Var_All = Sred(Man,n);    // Находим средний показатель по всем объектам.
//   float Var_min = fabs(Var_All-Man[0].Avg);  // Наименьший имеет номер 0.
//   int Nom=0;
//   for (int i=0;i<n;i++)
//      if (fabs(Var_All-Man[i].Avg)<Var_min)
//	     Nom=i;                 // Запоминаем номер самого среднего.
//   return Nom;
//}
//
//// Возвращает указатель на найденный объект===================
//Person * Sred_Stat_k(Person Man[],int n,int k)  // Передается n данных типа Person
//{
//   float Var_k = Sred_k(Man,n,k);    // Находим средний показатель по всем объектам.
//
//   float Var_min = fabs(Var_k-Man[0].Data[k]);  // Наименьший имеет номер 0.
//   Person * Nom = Man;	// Знает адрес нулевого элемента.
//   for (int i=0;i<n;i++)
//      if ( fabs(Var_k-Man[i].Data[k])<Var_min)
//	     Nom=Man+i;                 // Запоминаем номер самого среднего.
//   return Nom;
//}

// Поиск по фамилии===================================
Person * Found_Fam(char *Who, Person Man[], int n)
{
   for (int i=0; i<n; i++)
       if (strcmp(Who,Man[i].Name)==0)       // ==0, значит найдено.
		return Man+i;
   return NULL;				       //Если поиск неудачен.
}
