#include <math.h>
#include <iostream>

int main()
{
    int x, y;
    int x1, y1;
    std::cin >> x >> y >> x1 >> y1;
    int r = 1;

    if ( 
            (pow(x1,2) + pow( (y-y1),2 ) == 1 )
            ||
            (pow(y1,2) + pow( (x-x1),2 ) == 1 )
        )
    std::cout << "yes";
}