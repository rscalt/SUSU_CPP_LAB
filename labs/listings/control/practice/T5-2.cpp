/* 
Татьяна Ларина, читая очередной французский роман, подсчитала сумму номеров прочитанных страниц. Обозначим эту сумму через Q.
Определить номер последней прочитанной страницы. 
Учесть, что юная девица может быть не в ладах с арифметикой.
*/

#include <iostream>
using namespace std;

int main()
{
    int Q = 0; // == сумма номеров прочитанных страниц
    cout << "Enter Q: \n";
    cin >> Q;
    
    for(int q = 1, page_counter = 0; page_counter < Q; q++)
        {
        page_counter += q;
        if (page_counter == Q) //с арифметикой все в порядке...
        cout << "The last page is " << q << endl;
        else if (page_counter > Q)
            {
            cout << "Incorrect Q! ";
            cout << "Maybe you meant " << page_counter << "?" << endl; //... либо нет - тогда сориентируем.
            }
        }
}