#include "Classes.h"
#include <conio.h>
void main(void)
{
	Two Q1(1,22), Q2(1, 44);
	Two Q3 = Q1 + Q2;
	
	Q3.Out();

	++Q3;	       // Q3++
	Q3.Out();
	--Q3;	       // Q3--
	Q3.Out( );

	if (Q2 == Q3)
		cout << "Yes" << endl;
	else
		cout << "Not" << endl;
	bool Yes = Q2 == Q1;

	//Q3 = Q1 - Q2;
	//Q3.Out();
	//Q3 = Q1;
	// И то же самое для динамических объектов.
	
	Two *t1 = new Two(1,2);
	t1->Out();
	//++t1;
	t1->Out( );
	++*t1;
	t1->Out();

	Two *t2 = new Two(4,7);
	Two *t = new Two;

	*t = *t1 + *t2;

	*t = t1->operator-(*t2);
    t->Out( );
	t1 = t1;
	*t1 = *t2;

//	Q1 = Q2;	// Копия данных из Q2
//  Two A1(1,2), A2(13,24);
//  Two A3;		// Нулевой.
//  int aa, bb;
//  int cc = aa + bb;
//  A3 = A1 + A2;
//  A3.Out();
//  ++A3;
//  A3++;					
//  A3.Out();
//  A3++;
//  A3.Out();
//  A3 = A3+5;
// 
//  A1.Set(12,10);
//  A2.Set(1,10);
//  A3 = A1 - A2;
//  A3.Out();
//  --A3;
//  A2 = A3-- + A2;
//  A3.Out();
//  if (A1==A2)
//	  cout << "Yes\n";
//  else
//	  cout << "No\n";
//  t->Out();
}

