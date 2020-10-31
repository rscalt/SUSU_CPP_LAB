#include <iostream>
using namespace std;
#include <math.h>
/*
Даны два луча, Alpha и Beta.
Найти: угол наклона биссектрисы и угол между лучами.
В град. мере с точностью до град.
*/
void main(void)
{
	int Alpha, Beta;	// Дано.
	int A_B, gamma;		// 
	cout << "Input то-то и то-то";
	cin >> Alpha >> Beta;
	// Угол между лучами.
	if (Alpha > Beta)
		A_B = Alpha - Beta;
	else
		A_B = Beta - Alpha;
	gamma = (int) (Alpha + Beta)/2.0;
	cout << A_B << "  " << gamma << endl;
	system("pause");
}