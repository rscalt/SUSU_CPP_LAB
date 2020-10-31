#include <fstream>
#include <iostream>
#include <string.h>
#define  LEN_MAX 10
using namespace std;
// Вывод массива на экран.
void Print_mas (int mas[], int len)    //Длина не изменяется, len-значение
{ int i;
	cout <<"Is array:\n";
	for (i=0;i<len;i++)
	   cout << mas[i] << " ";
	cout << endl;
}
// Вывод массива в файл.
void Print_mas(string F_Name, int mas[], int len)  //Длина не изменяется, len-значение
{
	int i;
	ofstream F_out; 
	F_out.open(F_Name);
	F_out << "Is array:\n";
	for (i = 0; i<len; i++)
		F_out << mas[i] << " " ;
	F_out << endl;
	F_out.close();
}

// Ввод массива с окончанием по eof(Ctrl_Z)
void Input_mas (int mas[], int &len)    // Массив длиной len<10
{
	len = 0;
	do                                  // a) конец файла.
	{                                   // б) длина <10.
		cin >> mas[len];                // размер массива
		len++;
	} while (!cin.eof() && len<LEN_MAX);
}

// Ввод массива с окончанием по eof из файла.
void Input_mas (string F_Name, int mas[], int &len)    // Массив длиной len<100
{
len=0;
ifstream F_in;
F_in.open(F_Name);
do                                  // a) конец файла.
   {                                // б) длина <100.
	 F_in >> mas[len];              // размер массива
	 len++;
   }
while(!F_in.eof() && len<LEN_MAX);
}

// Пример 3. Чтение (запись) строк из текстового файла.
// Обмен и преобразование осуществляется построчно.
void Input_text(string F_Name, string Text[], int &len)
{
	ifstream File;
	char buff[80];
	File.open(F_Name, ios::in);      // Файл открыт для ввода
// Считываем из файла все строки.
	len = 0;
	while (File.getline(buff, 80))
	{
		Text[len] = buff;
		len++;
	}
		File.close(); // закрываем файл
}
void Out_text(string F_Name, string Text[], int &len)
{

}


//int q ;
//while (!feof(inS))
//{
//fgets(str,100,inS);       // Наибольшая длина строки =100.
//printf("%s",str);     // Вывод на экран.
//str = Add_10(str);    // См. кодировки.
//fputs(str, outS);
//}
