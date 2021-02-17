//1.Дан положительный угол в радианах. 
//Найти, сколько градусов и минут содержит данный угол

#include <iostream>

int main()
{
    const float PI = 3.14159265359F;
    float radians = 0;
    float degrees_float = 0;
    int degrees_int;
    int minutes_int;
    std::cout << "Enter radian value: \n";
    std::cin >> radians;
    
    degrees_float = radians*180/PI;
    degrees_int = static_cast<int>(degrees_float);
    minutes_int = (degrees_float - degrees_int)*60; //60 mins per degree
    std::cout << "Floating point degrees: " << degrees_float;
    std::cout << "\n";
    std::cout << "Integral degrees: " << degrees_int;
    std::cout << "\n";
    std::cout << "Integral minutes: "<< minutes_int;
    std::cout << "\n";
}