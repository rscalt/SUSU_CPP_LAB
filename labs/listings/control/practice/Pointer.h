/* ���������� � ������ ���������� � ����������.*/
void f1(void)
{
char  c = 'j';         // 1 ����
int   x = 5;           // 4 �����
float y = 3.14;        // 4 �����
char  *cptr;           // 4 �����
int   *xptr;           // 4 �����
float *yptr;           // 4 �����
int p = sizeof(yptr);
   cptr = &c;
   xptr = &x;
   yptr = &y;         //����������� - 16-������ ��������.
cout << cptr << endl;
cout << xptr << endl;
cout << yptr << endl;
}

#include <stdio.h>
/*������ �� ��������� ������ � �������� ���������.*/
void f3(void)
{  
  int a = 10;
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
   int *delta_p_prev;
   int *delta_p_next;

    for (p = pa; p >= pd; p--)
    {
          delta_p_prev = p;
          delta_p_next = p-1;
          std::cout << "\n Address " << p << " Value " << *p << " Delta_Address " << (delta_p_next - delta_p_prev) << endl;
    }

    
    cout << "---------------------------------------------\n";
 //�����: ��������� ������� � �������� ������.
 // 4.
/*    cout << "\n Address " << pb+1 << " Value " << *(pb+1) << endl;
   cout << "\n Address " << pb-1 << " Value " << *(pb-1) << endl;
   cout << "\n R (d - a) = " << pd - pa << endl;
   cout << "3---------------------------------------------\n";
   _getch(); */
}


