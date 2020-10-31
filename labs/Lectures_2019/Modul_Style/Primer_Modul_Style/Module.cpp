//---------------------------------------------------------------------------
#include "Module.h"
#include <stdio.h>
#include <conio.h>
#define N 10
//---------------------------------------------------------------------------

int main(void)
{
// Описание данных - Массив имен + матрица баллов.
char Names [N][20];    // Массив имен.
int Balls [N][4];      // Суммы баллов- 4 cтолбец.
int n;   		       // Число строк
char Lesson [4][12]={"MS Word","MS Excel","MS Access","Итого"};
// Файлы данных объявлять здесь, здесь открывать (закрывать).
// Подкачка данных - при открытии приложения.
// Типа меню.
FILE *names;
names = fopen("Names.txt","wt");
FILE * Res;
int key;
do
{
	printf("Select point of nenu:\n");
	printf("1-Input names\n");  // Ввести с консоли и сохранить.
	printf("2-Input balls\n");
	printf("3-Output results\n");
	printf("4-Output Best\n");
	// ...
	printf("8-Exit\n");
	scanf("%d",&key);
	switch (key)
	{
// Ввод имен и сохранение в текстовом файле Names.txt.
	case 1: { Input_name(names,Names,n); break;}
// Ввод баллов каждого слушателя и сохранение в двоичном файле Balls.bin.
	case 2: {
			fclose (names);
			names = fopen("D:\\Work\\ЭиУ-I\\Lectures_2013\\Modul_Style\\Primer_Modul_Style\\Names.txt","rt");
			//D:\Work\ЭиУ-I\Lectures_2013\Modul_Style\Primer_Modul_Style
			Res= fopen("Balls.bin","wb");
			Input_balls(names, Res, Names, Balls, n);
            fclose(Res);
			break;
			}
// Вывод результатов из Balls.bin на консоль.
	case 3: { 
		    Res= fopen("Balls.bin","rb");
		    Output(Res, Names, Balls, n, Lesson);
            fclose(Res);
			break;
			}
// Сортировка массивов и вывод на консоль.
// 1 вариант - сортировать и сохранить в файле.
// 2 вариант - сортировать массивы в ОП.
	case 4: { 
		    
		    ;
			break;
			}
	//...
	case 8: { return 1;}
	default: { return 1;}
		;
	}
}while (key!=8);
getch();

}
