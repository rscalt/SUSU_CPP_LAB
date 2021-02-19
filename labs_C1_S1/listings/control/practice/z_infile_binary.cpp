#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

struct data
{
    int a;
    int b;
    int c;
    char x[12] = "hello!";
};

int main()
{
    ofstream os;
    os.open("data.bin", std::ios::binary);


    data d;

    d.a = 1877;
    d.b = 1029;
    d.c = 40115;

    os << d.a << "\n";
    os << d.b << "\n";
    os << d.c << "\n";

    strcpy(d.x, "abcdefghijk");
    os << d.x << "\n";

    strcpy(d.x, "hello!");
    os << d.x << "\n";

    os.close();


    ifstream is;
    is.open("data.bin", std::ios::binary);

    cout << is.rdbuf();
    cout << endl;

    os.close();

    return 1;
}