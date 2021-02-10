/* 
Дети встают по кругу и начинают считалку, в которой выбываетn-й ребенок, 
после чего круг смыкается. 
Считалка повторяется, пока не останется один ребенок. 
Использовать функции обработки массивов, чтобы узнать, кто останется 
*/

#include <iostream>
#include <iomanip>

using namespace std;

float *create_circle (float *arr, int &arr_length); //создание динамического массива - натурального ряда чисел
void print_array(float *arr, int arr_length); ////детализированный вывод float-массива
float number_game(float *arr, int arr_length); //считалка с выбыванием до тех пор, пока не останется только один; возвращает номер оставшегося.

int main()
{
    //dirty hack для создания массива переменной длины
    int array_length = 1; 
    float *new_array_ptr = NULL;

    new_array_ptr = create_circle(new_array_ptr, array_length); //создаем толпу из N человек
    float *CROWD_ARRAY_PTR = new_array_ptr; //сохраняем указатель
    new_array_ptr = NULL; //обнуляем

    print_array(CROWD_ARRAY_PTR, array_length); //как было
    float last = number_game(CROWD_ARRAY_PTR, array_length); //поиграли
    print_array(CROWD_ARRAY_PTR, array_length); //либо array_length = 1 //как стало

    cout << endl;
    cout << "The last man standing is " << last; //кто остался
}

//создание динамического массива - натурального ряда чисел
float *create_circle (float *arr, int &arr_length)
{
    cout << "Enter crowd size: ";
    cin >> arr_length; //переопределяем емкость массива
    arr = new float[arr_length](); //выделяем заданную память

    for (int i = 0; i < arr_length; i++)
        arr[i] = i+1;

    return arr; //возвращаем &arr[0]
}

//строчный вывод float-массива
void print_array_string(float *arr, int arr_length)
{
    for (int i = 0; i < arr_length-1; i++)
    {   
        cout << arr[i] << ", ";
    }
        cout << arr[arr_length-1];
}

//детализированный вывод float-массива
void print_array(float *arr, int arr_length)
{
    cout << "Array at " << arr << ":\n";

    cout << "index\t"
         << "element\t"
         << "hex_address\t"
         << "dec_address\n";
    for (int i = 0; i < arr_length; i++)
    {
        cout << setw(2) 
             << i << "\t"; //index

        cout << setw(5)
             << arr[i] << "\t"; //element

        cout << setw(10) 
             << &arr[i] << "\t"; //hex_address

        printf("%d", &arr[i]); //dec_address

        cout << "\n";
    }
}

//считалка с выбыванием до тех пор, пока не останется только один
float number_game(float *arr, int arr_length)
{
    int word_count; //слов в считалке; 
    //после выбывающего начинает считать тот, кто следующий в круге
    cout << endl;
    cout << "Enter words number: ";
    cin >> word_count;

    int index_to_out = 0; //кто выбывает
    int last_index = arr_length - 1; //последний индекс
    int round = 1;

    while (arr_length > 1)
    {
        cout << "==========================" << endl;
        cout << "Round " << round << " starts with circle:";
        cout << endl;
        print_array_string(arr, arr_length);
        cout << "\n";

        index_to_out = (word_count%arr_length)-1; //индекс того, кто выбывает; периодичность (движение по кругу) процесса реализуется через modf либо %
        if (word_count == arr_length) //единожды во время считалки; иначе получим index_to_out < 0
            index_to_out = word_count-1;
        
        cout << "A member leaves the circle: ";
        cout << "(i: " << index_to_out << "; num: " << index_to_out+1;
        cout <<"; value: " << arr[index_to_out] << ", word count: " << word_count << ")";
        cout << endl;

        for (int i = index_to_out; i < last_index; i++) //смещаем элементы влево
            arr[i] = arr[i+1]; //текущий элемент = следующему
        arr[last_index] = 0; //обнуляем дубликат
        arr_length--;
        
        cout << "Round " << round << " ends with circle:\n";
        print_array_string(arr, arr_length);
        cout << endl;

        round++;
    }
    return arr[0];
}