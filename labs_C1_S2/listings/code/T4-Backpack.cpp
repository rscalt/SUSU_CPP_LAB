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
class Item
{
protected:
    int cost;
    int weight;
    string description;

public:
    virtual void print() = 0;
    virtual string get_description() = 0;
};

////////////////////////////////////////////////////////////////////////
class Health_potion : public Item
{
private:
    int regen = 150;

public:
    Health_potion()
    {
        cost = 100;
        weight = 10;
        description = "Health potion";
        cout << "\nA health potion have been created.";
    }

    ~Health_potion()
    {
        cout << "\nA health potion have been destroyed.";
    }

    void print()
    {
        cout << description;
    }

    string get_description()
    {
        return description;
    }
};
////////////////////////////////////////////////////////////////////////
class Mana_potion : public Item
{
private:
    int regen = 50;

public:
    Mana_potion()
    {
        cost = 120;
        weight = 15;
        description = "Mana potion";
        cout << "\nA mana potion have been created.";
    }

    ~Mana_potion()
    {
        cout << "\nA mana potion have been destroyed.";
    }

    void print()
    {
        cout << description;
    }
    string get_description()
    {
        return description;
    }
};
////////////////////////////////////////////////////////////////////////
class Magic_staff : public Item
{
private:
    int damage = 300;

public:
    Magic_staff()
    {
        cost = 1000;
        weight = 50;
        description = "Magic staff";
        cout << "\nA magic staff have been created.";
    }

    ~Magic_staff()
    {
        cout << "\nA magic staff have been destroyed.";
    }

    void print()
    {
        cout << description;
    }
    string get_description()
    {
        return description;
    }
};
////////////////////////////////////////////////////////////////////////
class Iron_sword : public Item
{
private:
    int damage = 200;

public:
    Iron_sword()
    {
        cost = 600;
        weight = 75;
        description = "Iron sword";
        cout << "\nA iron sword have been created.";
    }

    ~Iron_sword()
    {
        cout << "\nA iron sword have been destroyed.";
    }

    void print()
    {
        cout << description;
    }
    string get_description()
    {
        return description;
    }
};
////////////////////////////////////////////////////////////////////////
class Shortbow : public Item
{
private:
    int damage = 100;

public:
    Shortbow()
    {
        cost = 500;
        weight = 20;
        description = "Shortbow";
        cout << "\nA Shortbow have been created.";
    }

    ~Shortbow()
    {
        cout << "\nA Shortbow have been destroyed.";
    }

    void print()
    {
        cout << description;
    }
    string get_description()
    {
        return description;
    }
};
////////////////////////////////////////////////////////////////////////

//емкость сумки
const int global_backpack_max_size = 15;

//сумка
class Backpack
{

private:
    //массив указателей на предметы
    Item *m_arr_ptr_item[global_backpack_max_size];
    //индекс последнего предмета
    int last_index = 0;
    //копия глобальной емкости (константа)
    const int m_max_size = global_backpack_max_size;

public:
    //=========================================================================
    Backpack()
    {
        cout << "\nA backpack have been created.";
    }

    ~Backpack()
    {
        cout << "\nA backpack have been destroyed.";
    }
    //=========================================================================

    //добавление предмета
    void add_item(Item *i1)
    {
        //cout << "  \nLast index is " << last_index;
        m_arr_ptr_item[last_index] = i1;
        last_index++;
        cout << "  \n Item have been added.";
    }

    //удаление предмета
    void remove_item(int item_number)
    {
        int index = item_number - 1;

        //перемещаем предметы с учетом освободившегося места
        m_arr_ptr_item[index] = nullptr;
        for (int i = index; i < m_max_size - 1; i++)
            m_arr_ptr_item[i] = m_arr_ptr_item[i + 1];

        //корректируем last_index
        last_index--;
        cout << "  \nItem #" << item_number << " have been removed.";
    }

    //ревизия содержимого
    void print_content()
    {
        cout << "  \nThe backpack has:";
        for (int i = 0; i < last_index; i++)
        {
            cout << "\n"
                 << i + 1 << ". ";
            m_arr_ptr_item[i]->print();
        }
    }

    //поиск предмета по указанному свойству
    void search_item(string str_query)
    {
        cout << endl << str_query << ": ";
        bool is_found = false;
        for (int i = 0; i < last_index; i++)
        {
            if (m_arr_ptr_item[i]->get_description() == str_query)
            {
                is_found = true;
                cout << endl
                     << str_query << " is at #" << i + 1;
            }
        }

        if (is_found == false)
            cout << "  \nThe item was not found.";
    }

    //подсчет количества предметов по указанному типу
    int count_item_type(string str_query)
    {
        int count = 0;
        for (int i = 0; i < last_index; i++)
        {
            if (m_arr_ptr_item[i]->get_description() == str_query)
                count++;
        }
        return count;
    }
};
////////////////////////////////////////////////////////////////////////
int main()
{
    Item *ptr_item1, *ptr_item2, *ptr_item3, *ptr_item4, *ptr_item5, *ptr_item6, *ptr_item7;
    ptr_item1 = new Shortbow;
    ptr_item2 = new Health_potion;
    ptr_item3 = new Mana_potion;
    ptr_item4 = new Iron_sword;
    ptr_item5 = new Magic_staff;
    ptr_item6 = new Mana_potion;
    ptr_item7 = new Magic_staff;

    Backpack backpack1;
    backpack1.add_item(ptr_item1);
    backpack1.add_item(ptr_item2);
    backpack1.add_item(ptr_item3);
    backpack1.add_item(ptr_item4);
    backpack1.add_item(ptr_item5);
    backpack1.add_item(ptr_item6);
    backpack1.add_item(ptr_item7);

    backpack1.print_content();
    backpack1.remove_item(2);
    backpack1.print_content();
    backpack1.add_item(ptr_item2);
    backpack1.print_content();

    cout << endl;
    backpack1.search_item("Health potion");
    cout << endl;
    backpack1.search_item("Mana potion");
    cout << endl;
    backpack1.search_item("Iron sword");


    cout << endl;

    cout << endl;
    cout << "The number of Iron swords in the backpack is "
         << backpack1.count_item_type("Iron sword")
         << ".";

    cout << endl;
    cout << "The number of Mana potions in the backpack is "
         << backpack1.count_item_type("Mana potion")
         << ".";
}
