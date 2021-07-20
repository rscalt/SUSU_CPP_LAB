#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
using namespace std;
class Two {
   int a;
   float b;     // ��������� ����� ������
public:
// ����������� ���������������� ������
void Out() {
      cout << "a=" << a << " b= " << b << endl;
   }
Two (int a1, float b1) {  // �����������
    a = a1;
    b = b1;
}
Two () {                  // �����������
	a = b = 0;
}
void Set(int aa, float bb) {
	a = aa;
	b = bb;
}
// ���������� �������� �������� 
friend Two operator + (Two &t1, Two &t2);    // ������� (Q1,Q2)
// ���������� ��� this.
Two operator - (Two &t2)  	// Q1.�����()	 Q2.�����()		
{
	Two tmp;
	tmp.a = this->a - t2.a;
	tmp.b = b - t2.b;
	return tmp;
}

// ���������� ������� ��������  
friend Two operator ++ (Two &t);
// this
Two operator --( )		// ����������.
{
	this->a--;
	this->b -= 1;
	return *this;
}
Two operator --(int) 	// �����������.
{
	Two temp = *this;
	--*this;
	return temp;
}

// ���������� �������� ������������: 
// ������ ��� ����� ������.
Two operator = (Two &T)		// A = B;
{
	a = T.a; 
	this->b = T.b;
	return *this;
}

// ���������� ��������� A==B: ���������� ���������� ��������.
bool operator == (Two &t)
{
	return (this->a == t.a) && (fabs(this->b - t.b) <= 0.001);
}
// ��������� ���� ����������:
friend Two operator + (Two &t, int n);
};

// ==================================================
// ���������� �������� � �������������� ������������� �������.
Two operator + (Two &t1, Two &t2) // A + B
{	
    Two tmp;
	tmp.a= t1.a + t2.a;
	tmp.b= t1.b + t2.b;
	return tmp;
}
Two operator ++(Two &t)		// �������� �������� ++ ��� Two: Two a;  a++; ++a;
{
	t.a++;
	t.b += 1;
	return t;
}
// �������� ������� Two � ������.
Two operator + (Two &t, int n)
{
Two tmp;
	tmp.a= t.a+n;
	tmp.b= t.b+n;
	return tmp;
}

/*
// Define prefix increment operator.
Point& Point::operator++()
{
_x++;
_y++;
return *this;
}
// Define postfix increment operator.
Point Point::operator++(int)
{
Point temp = *this;
++*this;
return temp;
}
*/









int NOD(int a, int b)
{
int c;
   while (b) 
   {
      c = a % b;
      a = b;
      b = c;
   }
   return abs(a);
 }



