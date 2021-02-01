
#include <iostream>
void average(float, float&);

int main()
{
 float Point = 2;
 int Point_int = 2;
 float avg = 0;
 average(Point, avg);
 std::cout << avg;
 float array[Point_int];
}


void average(float Point, float &avg) 
{
    float value;
    float sum;
	for (int i = 0; i < Point; i++)
        {
        std::cin >> value;
        sum += value;
        }
    avg = sum/Point;
}