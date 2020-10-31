//---------------------------------------------------------------------------
#include "Strings.h"
//---------------------------------------------------------------------------
//void compress_1( char []);
//void compress_2( char *);

void main(void)
{
/* Foundkey();
for(int i=175;i<=207;i++)
  printf ("%c",i);
 getch();*/
 //Кодовая таблица
Code(); 

//Str1 - строковые константы.
 Str1();
// Str2 - Инициализация , ввод и вывод строк.
Str2();
// Str3 - Строки и указатели, косвенная адресация
 // Str3();
// Прямая и косвенная адресация - копирование строки
// Copy_Str();

// Пример функций преобразования строки.
// Сжать строку, удалив из нее лишние пробелы.
char *str = new char[80];
/*
printf("\nInput string\n");
   gets(str);
printf("Is string: \n");
   puts(str);
compress_1(str);
printf("Is string: \n");
   puts(str);
printf("\====================================\n");
printf("\nInput string\n");
   gets(str);
printf("Is string: \n");
   puts(str);
   compress_2(str);
printf("Is string: \n");
  puts(str);
printf("\====================================\n");
*/
/*
char Str[]="";

char *My_Str = "One Two Three Four Five Six ";
char *Word;
Word = Found_word(My_Str);
puts(Word);
*/

//char * Rus = "Мама мыла раму cdsffasdf 2123 $#@ папа пиво пил";
//printf ("%s",ac(Rus));
//
//char * my_str = "1 2 3 4 5.";
//
//// Копировать строку Old_str по адресу New_str
//	 char * Old_str  = "Cтрока текста";
//Old_str = ac(Old_str);
//	 char   New_str[80];
//
//	 strcpy_s(New_str,Old_str);
//
//	 puts(New_str);
//// Конкатенация строк
//
//	 strcat(New_str,Old_str);
//	 puts(New_str);
//
//// Поиск вхождения подстроки в строку.
//	 char * found = "ока";
//	 char * yes;
//	 yes = strstr(Old_str,found);
//
//	 if(yes==NULL)
//		printf ("Нет");
//		else printf("Есть '%s'",yes);
_getch();

}