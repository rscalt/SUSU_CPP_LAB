
#include "Files.h"
//---------------------------------------------------------------------------
 /*Чтение массива из файла.
  Длина массива может быть определена при вводе.
  Массив в текстовом файле "data.txt". Там же результат. */
#define  LEN_MAX 10

int main(void)
{
// Пример 1. Вывод массива в текстовый файл.
int   Arr[LEN_MAX] = {1,2,3,4,5};
int   len=5;

Print_mas(Arr,len);			// На консоль.

// Вывод в текстовый файл
string Name = "Data.txt";
Print_mas(Name, Arr,len);	// В файл Data.txt.


// Пример 2. Ввод массива из текстового файла.
Input_mas(Arr, len);		// Из консоли
Print_mas(Arr, len);

Input_mas("In_data.txt", Arr, len);		// Из файла In_data.txt. len определяется при вводе.
Print_mas(Arr, len);

// Пример 3. Чтение(запись) строк из текстового файла.
string Text[10];
int ls = 0;
Input_text("Text.txt", Text, ls);

}









//  прототипы:
//	char *fgets(char *s, int n,  FILE *stream);
//	int fputs  (const char *s,   FILE *stream);

