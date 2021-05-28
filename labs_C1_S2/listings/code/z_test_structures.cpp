//z_test_structures
#include <iostream>
using namespace std;

void cout_table_header();
//==============================
struct root
{
    drive hdd;
    drive ssd;
    drive flash;
    ram stationary;
    ram notebook;
};

struct drive
{
    string maker;
    string model;
    int size;
    double price;
};

struct ram
{
    string maker;
    string model;
    int volume;
    double price;
};
//==============================
int main()
{
    root base;
    drive id_1, id_2;
    base.hdd.maker;

    base.hdd.maker = "wd";
    base.hdd.model = "green";
    base.hdd.size = 1000;
    base.hdd.price = 200;

    cout_table_header();
    cout << id_1.maker << "\t" << id_1.model << "\t" << id_1.size << "\t" << id_1.price;
    cout << endl;
    cout << id_2.maker << "\t" << id_2.model << "\t" << id_2.size << "\t" << id_2.price;

    id_2 = id_1;

    cout << endl;
    cout << endl;

    cout_table_header();
    cout << id_1.maker << "\t" << id_1.model << "\t" << id_1.size << "\t" << id_1.price;
    cout << endl;
    cout << id_2.maker << "\t" << id_2.model << "\t" << id_2.size << "\t" << id_2.price;
}

void cout_table_header()
{
    cout << "maker"
         << "\t"
         << "model"
         << "\t"
         << "size"
         << "\t"
         << "price"
         << "\n";
}

void cout_field()
{
    cout << "maker"
         << "\t"
         << "model"
         << "\t"
         << "size"
         << "\t"
         << "price"
         << "\n";
}