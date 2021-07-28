/* 
Практическое задание 5
Тема: Множественное наследование, виртуальные функции и абстрактные
классы.
1. Создать базовый класс «Животное». Класс содержит название животного.
2. Создать дочерние классы «Кошка», «Собака», «Хомяк» с описанием животного. Виртуальные методы: «Как выглядит» и «Как говорит».
3. Выполнить проверку для каждого вида производного объекта 
*/

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
class Animal
{
protected:
    string name;

public:
    virtual string get_name() = 0;        //имя
    virtual string get_description() = 0; //как выглядит
    virtual string get_voice() = 0;       //как говорит
};
////////////////////////////////////////////////////////////

class Cat : public Animal
{
private:
    string description;
    string voice;

public:
    Cat(string arg_name)
    {
        name = arg_name;
        description = "\nThis is a cat.";
        voice = "\nIt says \"Meow~\"";
        cout << "\nA cat have been created.";
    };
    ~Cat()
    {
        cout << "\nA cat have been gone...";
    };
    virtual string get_name()
    {
        return name;
    }

    virtual string get_description()
    {
        return description;
    }

    virtual string get_voice()
    {
        return voice;
    }

};

class Dog : public Animal
{
private:
    string description;
    string voice;

public:
    Dog(string arg_name)
    {
        name = arg_name;
        description = "\nThis is a dog.";
        voice = "\nIt says \"Woof--\"";
        cout << "\nA dog have been created.";
    };
    ~Dog()
    {
        cout << "\nA dog have been gone...";
    };
    virtual string get_name()
    {
        return name;
    }

    virtual string get_description()
    {
        return description;
    }

    virtual string get_voice()
    {
        return voice;
    }
    
};

class Hamster : public Animal
{
private:
    string description;
    string voice;

public:
    Hamster(string arg_name)
    {
        name = arg_name;
        description = "\nThis is a hamster.";
        voice = "\nIt says \"...\"";
        cout << "\nA hamster have been created.";
    };
    ~Hamster()
    {
        cout << "\nA hamster have been gone...";
    };
    virtual string get_name()
    {
        return name;
    }

    virtual string get_description()
    {
        return description;
    }

    virtual string get_voice()
    {
        return voice;
    }
};

int main()
{
    const int ANIMALS_COUNT = 4; //всего животных

    Animal *ptr_arr_animals[ANIMALS_COUNT];
    ptr_arr_animals[0] = new Cat("Barsik");
    ptr_arr_animals[1] = new Dog("Whiskey");
    ptr_arr_animals[2] = new Hamster("Sweep");
    ptr_arr_animals[3] = new Cat("Ciri");

    for (int i = 0; i < ANIMALS_COUNT; i++)
    {
        cout << "\nIts name is " << ptr_arr_animals[i]->get_name();
        cout << ptr_arr_animals[i]->get_description();
        cout << ptr_arr_animals[i]->get_voice();
        cout << endl;
    }
}
