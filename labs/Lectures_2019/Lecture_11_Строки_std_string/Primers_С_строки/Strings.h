//---------------------------------------------------------------------------

#ifndef StringsH
#define StringsH
//---------------------------------------------------------------------------
#endif

#include <stdio.h>
//#include <bios.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define ESC 0x11b
//
//void Foundkey(void)
//{
//unsigned char key;
//do
//   {	key=_getch();              /*ожидаемое значение*/
//	printf("Symbol is %c, his (16) code is %#0x, his 10 code is %d\n",key,key,key);
//   }
//while (key !=ESC);
//}
//
//
void Code(void)
{
 int  i,j;
 for (i = 0; i < 16; i++)
 {
  for (j= 0; j < 16; j++)
	 { // if (16*i+j >7 && 16*i+j<14) continue;
	 printf(  "%c ",  16*i+j);     //символьное представление кода символа
	 }
  printf("\n");
 }
}
//
//
//
////Str1 - строковые константы.
void Str1(void)
{
// Размещение в памяти переменных символьного типа.
printf ("%d\n",  sizeof(int));
printf ("%d\n",  sizeof(char));
printf ("%d\n",  sizeof(unsigned char));
//Esc последовательности в строках
printf ("%s\n","Is String");          // без особенностей
printf ("%s\n","Slash is written \\  ");  // слэш
printf ("%s\n","Character \"apostrof\" written double");   // апостроф
printf ("%s\n","The long string \
				can bi break on \
				variable parts -  \
				real this is one string.");
printf ("%s\n","The long string \n can bi break on\n variable parts - \n real this is one string.\n");
}
//
////Str2 - Инициализация строк, ввод вывод строк.
void Str2(void)
{
char str_1[10];  //Значения не присвоены
char str_1_2[] = {'I','s',' ','C','h','a','r','\0'};  //массив символов
char str_2[] = "Character";  // 10 byte
char str_3[] = "Primer & Primer";     // текстовая строка
char * str_4 = "Primer of string";    // указатель
char * str_5;    //объявлен указатель, память НЕ выделена
char * str_6=""; //Пустая строка
//Вывод строк
int  i = 0;
//1. Как строка - формат %s
printf("%s\n", str_2);
//2. Как последовательность символов - формат %c
i=0;
while ( str_2[i]!='\0')     //while (0), неявно последний '\0'
{
	printf("%c", str_2[i++]);
} ;
printf("\n");
//3. Как строка - без формата
puts (str_3);
////Особенности ввода.
//scanf_s ("%s",str_1);	// ввод текста до пробела
//	printf("%s",str_1);
////Ввод строки.
//_gets(str_1);
//putchar ('\n');
//_gets(str_4);	   // Ввод текста до <ENTER>
//puts(str_4);       // Возможная ошибка- выход за длину массива.
}
//// Строки и указатели, косвенная адресация
//
//void Str3(void)
//{
//   char * str = "Primer";  // 7 байт
//   char * pts;             //указатель на строку
//// Функции ввода-вывода строк
//   _gets (str);       // Нельзя ввести больше - ошибка.
//   puts (str);
////  gets (pts); - ошибка, т.к.память для  pts не выделена.
////  Присваивание значения указателю:
//   pts = str ;                 //как будто i = 0 для операции []
//   pts += 4;                  //сразу 14-й символ строки str
//   * pts = 0;                  //здесь будет конец строки (15-й символ)
//   pts = str;
//   pts++;                      //так движемся по строке смещая указатель
//   pts++;                      //Ошибка - выход за пределы строки.
//   pts = str;                  // Встали в начало строки
//   while ( * pts )             // Пока не показывает на последний символ
//   {
//	   printf("%c",*pts++);    // посимвольный перебор
//   };
//   printf("\n");
//   pts = str;
//   while ( * pts++ )
//   {
//	   *pts++ ='@';            // посимвольный перебор и изменение значения
//   };
//   puts(str);
//}
//// Прямая и косвенная адресация - копирование строки
//void Copy_Str(void)
//{
//// Копирование одной строки в другую.
//// Важно, чтобы длины строк  совпадали.
//// Длина второй строки должна быть не больше.
//char Str1[] = "First string.";
//char *Str2  = "Second string.";
//// Прямая адресация элементов строк:
//int i=0;
//while (Str2[i]!='\0')
//{
//   Str1[i]=Str2[i];
//   i++;
//}
////Str1[i]='\0';
//puts(Str1);
//// Косвенная адресация элементов строк:
//char *Str3  = "Third string.";
//char *pts1, *pts3;
//pts1=Str1;
//pts3=Str3;
//while (*pts3!='\0')
//{
//   *pts1=*pts3;
//   pts1++;
//   pts3++;
//}
////*pts1='\0';
//puts(Str1);
//// Или одним махом
//pts1=Str1;
//pts3=Str2;
//while (  (*pts1++ = *pts3++) !='\0' );
//puts(Str1);
//// Что нельзя делать:
//// Использование в левой части присваивания
//// имени строки убивает ее.
///*
//pts = Str1;               //Показывает на первый элемент.
//// Копирование второй строки в первую.
//while (*pts !='\0')
//   {
//	  *pts = *str2++;
//	  pts++;
//   }
////ВНИМАНИЕ! Вторая строка убита изменением указателя!
//*/
//}
//
//void compress_1(char str[])
//{  int i,mid;
//			// i - рабочая переменная для поиска
//			// рядом стоящих пробелов
//			// mid - рабочая переменная для сдвига.
//   i=0;
//   while (i < strlen(str)-1)  // str[i]!='\0'
//	  if ( str[i]==' ' && str[i+1]==' ')
//	  {
//	  for (mid=i; mid<strlen(str); mid++)
//		   str[mid]=str[mid+1]; 	  //символ '\0'тоже сдвигается
//	  }
//	 else
//	 i++;     // по else, иначе некоторые сдвиги м.б. потеряны
//}
//
//void compress_2(char * str)
//{
//   char *ip, *mid;            // Рабочие указатели для поиска и для сдвига.
//   ip = str;
//   while ( *ip!='\0')
//      if ( *ip==' ' && *(ip+1)==' ')       //Два пробела рядом.
//	   {
//		  mid = ip;
//	      while (*mid !='\0')
//		{
//		  *mid =*(mid+1);
//		   mid++;
//		}
//	   }
//	 else
//	 ip++;
//}
//// Функция, возвращающая строку
//// Найти слово максимальной длины в строке.
//char *Found_word(char *Str)
//{
//puts (Str);
//char  *pts;
//char  *ptw_beg;
//char  *ptw_end;
//char  *ptw;
//char  *ptw_max;
//int w_len = 0;
//int w_len_max = 0;
//pts = Str;
//ptw_beg = pts;
//do
//{
//	if( (*pts == ' ') || (*pts == 0) )
//	{
//		ptw_end = pts;
//		w_len = ptw_end - ptw_beg;
//		if( w_len > w_len_max )
//		{
//			w_len_max = w_len;
//			ptw_max = ptw_beg;
//		};
//		printf("Len of word is: %d\n",w_len);
//		while ( * pts == ' ')   //Пропуск серии пробелов
//		   ++pts;
//		ptw_beg = pts;
//	}
//} while ( * pts++ );
//
//// Выделение памяти для новой строки
//char *Word=new char [w_len_max];
//char *pW=Word;
//// Копирование посимвольно
//for(pts = ptw_max; pts < ptw_max+w_len_max; pts++)
//   *pW++=*pts;
//*pW='\0';
//return  Word;
//}
//
//
////Пример использования библиотечных функций.
//int cou_dig (char *str)
//{  int count = 0;
//   while (*str !='\0')
//      { if (isdigit (*str) !=0 ) count++;
//	str++;
//       }
//   return count;
//}
//char *ac(char S[])
//{
//int i;
//for (i=0;S[i]!='\0';i++)
//{
//   if (S[i]>='А' && S[i]<='п')
//	   S[i]=S[i]-64;
//   else
//	 if (S[i]>='р' && S[i]<='я')
//	   S[i]=S[i]-16;
//	   else
//	   switch(S[i])
//	   {
//	   case 'Ё':  S[i]=S[i]+72;
//	   case 'ё':  S[i]=S[i]-57;
//	   }
//}
//S[i]='\0';
//return S;
//}
//
//
//
//
//
//
//
//
