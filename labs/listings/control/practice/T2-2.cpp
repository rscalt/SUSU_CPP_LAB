#include <iostream>

using namespace std;

int main()
{   
    char restart_char = 'n';

    do
    {
    int k1, k2; //системные блоки
    int m1, m2, m3; //мониторы
    int keyboard_price = 10000;
    int mouse_price = 5000;
    cout << "Enter k-prices: \n";
    cin >> k1 >> k2;
    cout << "Enter m-prices: \n";
    cin >> m1 >> m2 >> m3;
    /*=================================================*/
    int max_sum = 0;

    int k_max = 0;
    if (k1 > k2) k_max = k1; else k_max = k2;

    int m_max = 0;
    if (m1 > m2) m_max = m1; else m_max = m2;
    if (m3 > m_max) m_max = m3;

    max_sum = k_max + m_max + keyboard_price + mouse_price;
    cout << "Max PC price is " << max_sum << endl;
    /*=================================================*/
    int min_sum = 0;

    int k_min = 0;
    if (k1 < k2) k_min = k1; else k_min = k2;

    int m_min = 0;
    if (m1 < m2) m_min = m1; else m_min = m2;
    if (m3 < m_min) m_min = m3;

    min_sum = k_min + m_min + keyboard_price + mouse_price;
    cout << "Min PC price is " << min_sum << endl;
    /*=================================================*/
    cout << "Restart?\n";
    cin >> restart_char;
    } while (restart_char == 'y');
}