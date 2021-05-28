#include <iostream>
#include <iomanip>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class Part
{
private:

   string type;
   string vendor;
   string model;
   int quantity = 10;
   float price;

   int setw_width = 10;

public:

   void showheader()
   {
      cout << setw(setw_width);
      cout << "type";
      cout << "|";
      cout << setw(setw_width);
      cout << "vendor";
      cout << "|";
      cout << setw(setw_width);
      cout << "model";
      cout << "|";
      cout << setw(setw_width);
      cout << "quantity";
      cout << "|";
      cout << setw(setw_width);
      cout << "price";

      cout << "\n";
   }

   void getdata()
   {
      showheader();
      cout << "type: ";
      cin >> type;
      cout << "vendor: ";
      cin >> vendor;
      cout << "model: ";
      cin >> model;
      cout << "quantity: ";
      cin >> quantity;
      cout << "price: ";
      cin >> price;
   }

   void showdata()
   {
      cout << setw(setw_width);
      cout << type;
      cout << "|";
      cout << setw(setw_width);
      cout << vendor;
      cout << "|";
      cout << setw(setw_width);
      cout << model;
      cout << "|";
      cout << setw(setw_width);
      cout << quantity;
      cout << "|";
      cout << setw(setw_width);
      cout << price;

      cout << "\n";
   }

};
///////////////////////////////////////////////////////////////////////////

int main()
{
   int a,b;
   
   Part hdd[2]; //массив 
   int i = 0; //счетчик ввода
   
   for (i = 0; i < 2; i++)
   hdd[i].getdata(); //ввести данные

   for (i = 0; i < 2; i++)
   hdd[i].showdata(); //вывести данные
}
