/* Размещение в памяти переменных и указателей.*/
void f1(void)
{
char  c = '@';         // 1 байт
int   x = 5;           // 4 байта
float y = 3.14;        // 4 байта
char  *cptr;           // 4 байта
int   *xptr;           // 4 байта
float *yptr;           // 4 байта
int p = sizeof(yptr);
   cptr = &c;
   xptr = &x;
   yptr = &y;         //Иллюстрация - 16-ричное смещение.
cout << cptr << endl;
cout << xptr << endl;
cout << yptr << endl;
}

#include <stdio.h>
/*Пример на выделение памяти и смещение указателя.*/
void f3(void)
{  int a = 10;
   int b = 20;
   int c = 30;
   int d = 40;
   int *pa = & a;
   int *pb = & b;
   int *pc = & c;
   int *pd = & d;
 // 1.
   cout << "int  : " << sizeof(int) << endl;
   cout << "int *: " << sizeof(int *)<< endl;  
 // 2.
   cout << "\n Address " << pa << " Value " << *pa << endl;
   cout << "\n Address " << pb << " Value " << *pb << endl;
   cout << "\n Address " << pc << " Value " << *pc << endl;
   cout << "\n Address " << pd << " Value " << *pd << endl;
   cout << "---------------------------------------------\n";
 // 3.
   int *p;
   for (p = pa; p < pa - 4; p--)
	   cout << "\n Address " << p << " Value " << *p << endl;
   cout << "---------------------------------------------\n";
 //Вывод: выделение адресов в сегменте памяти.
 // 4.
   cout << "\n Address " << pb+1 << " Value " << *(pb+1) << endl;
   cout << "\n Address " << pb-1 << " Value " << *(pb-1) << endl;
   cout << "\n R (c - a) = " << pc - pa << endl;
   cout << "---------------------------------------------\n";
   _getch();
}


