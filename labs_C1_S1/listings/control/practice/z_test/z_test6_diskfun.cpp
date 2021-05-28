// diskfun.cpp
// Чтение из файла и запись нескольких объектов
#include <fstream> // для файловых потоков
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////
fstream file; // создать входной/выходной поток
string filename = "GROUPA.DAT";
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
class Person // класс Person
{
private:
    int last_id;
protected:
    int id;        //id
    char name[80]; // имя человека
    int age;       // его возраст

public:
    Person()
    {
        getLastID();
        clog << "Object 'Person' constructed successully with 'id' = " << id << "\n";
    }

    void getLastID()
    {
        file.open(filename, ios::app | ios:: binary);
        file.seekg(ios::end);
        int end_pos = file.tellg();
        int id_pos = end_pos - sizeof(Person);
        file.read(reinterpret_cast<char*>(&last_id), sizeof(int));
        file.close();
    }

    void getdata() // получить данные о человеке
    {
        std::cout << "\n Name: ";
        std::cin >> name;
        std::cout << " Age: ";
        std::cin >> age;
        id++;
    }

    void showHeader()
    {
        std::cout << "ID"
                  << "\t"
                  << "Name"
                  << "\t"
                  << "Age"
                  << "\n";
    }

    void showDataMax() // вывод данных о человеке

    {
        std::cout << "\n ID: " << id;
        std::cout << "\n Name: " << name;
        std::cout << "\n Age: " << age;
    }

    void showDataMin() // вывод данных о человеке
    {
        std::cout << id << "\t";
        std::cout << name << "\t";
        std::cout << age << "\t";
    }
};
///////////////////////////////////////////////////////
int main()
{

    bool showpos = false;
    bool showdata = false;
    bool addpers = false;
    bool searchpers = false;

///////////////////////////////////////////////////////
    Person pers; // создать объект Person
///////////////////////////////////////////////////////
    
    unsigned int action = 0;

menu:
{
    action = 0;

    system("pause");

    std::cout << "Choose action: [1-5] \n"
              << "1. Toggle display r/w position \n"
              << "2. Add a Person \n"
              << "3. Search a Person \n"
              << "4. Show full table \n"
              << "5. Exit program \n"
              << "   Action : ";
    std::cin >> action;
    std::cout << "\n";
}

    switch (action)
    {

    case 1:
    {
        std::cout << "Show positions? (0/1): ";
        std::cin >> showpos;
        goto menu;
    }

    case 2:
    {
        std::cout << "Add a Person? (0/1)? ";
        std::cin >> addpers;

        while (addpers == 1) // данные от пользователя - в файл
        {
            std::cout << "\nEnter a Person data: ";

            if (showpos == 1)
                std::clog << "\t Current write position is " << file.tellp();

            pers.getdata(); // получить данные
            // записать их в файл

            file.write(reinterpret_cast<char *>(&pers), sizeof(Person));
            //static int w_pos = 0;
            std::cout << "Add one more Person? (0/1)? ";
            std::cin >> addpers;
        }; // выход по 'n'
        file.close();
        goto menu;
    }

    case 3:
    {
        std::cout << "Search a Person? (0/1) ";
        std::cin >> searchpers;
        if (searchpers == true)
        {
            file.seekg(0, ios::end);
            int endposition = file.tellg();
            int pers_number = endposition / sizeof(pers);

            std::cout << "There are " << pers_number << " persons"
                      << " in the file '" << filename << "'"
                      << "\n";

            int position = 0;

            position = (pers_number - 1) * sizeof(int);
            file.seekg(position);

            //           //std::cout << "The last id is " << pers.getLastID();

            std::cout << "Enter a Person number: ";
            std::cin >> pers_number;

            position = (pers_number - 1) * sizeof(Person);
            file.seekg(position);
            file.read(reinterpret_cast<char *>(&pers), sizeof(pers));

            pers.showDataMin();
            std::cout << endl;
            file.close();
            goto menu;
        }
        file.close();
        goto menu;
    }

    case 4:
    {
        std::cout << "Show table data? (0/1) ";
        std::cin >> showdata;

        file.seekg(0); // поставить указатель на начало файла
        // считать данные о первом человеке
        file.read(reinterpret_cast<char *>(&pers), sizeof(pers));

        if (showdata == 1)
        {

            std::cout << "Showing contents of '" << filename << "':\n";
            pers.showHeader();
            while (file.good()) // Выход по EOF
            {
                if (showpos == 1)
                    std::clog << "\t Current read position is " << file.tellg();

                pers.showDataMin(); // считать данные о следующем
                std::cout << "\n";
                file.read(reinterpret_cast<char *>(&pers), sizeof(pers));
            }
        }
        file.close();
        goto menu;
    }

    case 5:
    {
        file.close();
        std::cout << "Program closed.";
        return 0;
    }

    default:
    {
        cout << "Input not recognized...";
        file.close();
        goto menu;
    }
    }
}
