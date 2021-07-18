#include <iostream> //cin/cout и стримы
#include <iomanip>  //reserved
using namespace std;

//system("pause") с новой строки
void sys_pause()
{
    cout << endl;
    system("pause");
}
struct link
{
    int d;
    link *next;
};

class linklist
{
private:
    link *last;

public:
    linklist()
    {
        last = nullptr;
    }

    void additem(int arg1)
    {
        link *newlink = new link;
        newlink->d = arg1;
        newlink->next = last;
        last = newlink;
    }
    void display()
    {
        link *current = last;
        while (current)
        {
            cout << current->d << endl;
            current = current->next;
        }
    }
};

int main()
{
    linklist linked_list;
    linked_list.additem(5);
    linked_list.additem(4);
    linked_list.additem(3);

    linked_list.display();

}