#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
using namespace std;
class Two {
   int a;
   float b;     // Приватные члены класса
public:
// Минимальная функциональность класса
void Out() {
      cout << "a=" << a << " b= " << b << endl;
   }
Two (int a1, float b1) {  // Конструктор
    a = a1;
    b = b1;
}
Two () {                  // Конструктор
	a = b = 0;
}
void Set(int aa, float bb) {
	a = aa;
	b = bb;
}
// Перегрузка бинарных операций 
friend Two operator + (Two &t1, Two &t2);    // Функция (Q1,Q2)
// Вызывается для this.
Two operator - (Two &t2)  	// Q1.Метод()	 Q2.Метод()		
{
	Two tmp;
	tmp.a = this->a - t2.a;
	tmp.b = b - t2.b;
	return tmp;
}

// Перегрузка унарных операций  
friend Two operator ++ (Two &t);
// this
Two operator --( )		// Префиксная.
{
	this->a--;
	this->b -= 1;
	return *this;
}
Two operator --(int) 	// Постфиксная.
{
	Two temp = *this;
	--*this;
	return temp;
}

// Перегрузка операции присваивания: 
// только как метод класса.
Two operator = (Two &T)		// A = B;
{
	a = T.a; 
	this->b = T.b;
	return *this;
}

// Перегрузка отношений A==B: возвращает логическое значение.
bool operator == (Two &t)
{
	return (this->a == t.a) && (fabs(this->b - t.b) <= 0.001);
}
// Различные типы параметров:
friend Two operator + (Two &t, int n);
};

// ==================================================
// Перегрузка операций с использованием дружественных функций.
Two operator + (Two &t1, Two &t2) // A + B
{	
    Two tmp;
	tmp.a= t1.a + t2.a;
	tmp.b= t1.b + t2.b;
	return tmp;
}
Two operator ++(Two &t)		// Алгоритм операции ++ для Two: Two a;  a++; ++a;
{
	t.a++;
	t.b += 1;
	return t;
}
// Сложение объекта Two с числом.
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



