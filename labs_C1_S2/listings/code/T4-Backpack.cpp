/* 
Практическое задание 4. Контейнерные классы
1. Опишите класс «Вещица», 
        описывающий название какой-нибудь вещи и ее свойства.
    Данные класса:
        Название, свойства.
    Методы класса:
        должны обеспечить минимальную функциональность объекта.
2. Опишите класс «Дамская сумочка», содержащий определенное количество различных вещиц. 
Определите методы 
    добавления и удаления вещей, 
    полной ревизии содержимого,
    поиска по названию и свойствам, 
    подсчета количества одинаковых вещиц, например, карандашей. 
*/

//здесь - вещица - item, дамская сумочка = backpack

#include <iostream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////////////////////
class health_potion
{
private:
    int cost = 100;
    int regen = 150;
    int weight = 10;
    string description = "\nThis is a health Potion.";

public:
    health_potion()
    {
        cout << "\nA health potion have been created.";
    }
    ~health_potion()
    {
        cout << "\nA health potion have been destroyed.";
    }
};
////////////////////////////////////////////////////////////////////////
class mana_potion
{
private:
    int cost = 120;
    int regen = 50;
    int weight = 15;
    string description = "\nThis is a mana Potion.";

public:
    mana_potion()
    {
        cout << "\nA mana potion have been created.";
    }
    ~mana_potion()
    {
        cout << "\nA mana potion have been destroyed.";
    }
};
////////////////////////////////////////////////////////////////////////
class magic_staff
{
private:
    int cost = 1000;
    int damage = 300;
    int weight = 50;
    string description = "\nThis is a magic staff.";

public:
    magic_staff()
    {
        cout << "\nA magic staff have been created.";
    }
    ~magic_staff()
    {
        cout << "\nA magic staff have been destroyed.";
    }
};
////////////////////////////////////////////////////////////////////////
class iron_sword
{
private:
    int cost = 600;
    int damage = 200;
    int weight = 75;
    string description = "\nThis is an iron sword.";

public:
    iron_sword()
    {
        cout << "\nA iron sword have been created.";
    }
    ~iron_sword()
    {
        cout << "\nA iron sword have been destroyed.";
    }
};
////////////////////////////////////////////////////////////////////////
class shortbow
{
private:
    int cost = 500;
    int damage = 100;
    int weight = 20;
    string description = "\nThis is a shortbow.";

public:
    shortbow()
    {
        cout << "\nA shortbow have been created.";
    }
    ~shortbow()
    {
        cout << "\nA shortbow have been destroyed.";
    }
};
////////////////////////////////////////////////////////////////////////