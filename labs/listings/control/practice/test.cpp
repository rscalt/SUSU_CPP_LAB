/* //считалка с выбыванием до тех пор, пока не останется только один
float number_game(float *arr, int arr_length)
{
    int word_count; //слов в считалке; 
    //после выбывающего начинает считать тот, кто следующий в круге
    cout << "Enter words number:";
    cin >> word_count;

    int index_to_out = 0; //кто выбывает
    int index_to_start = 0; //кто начинает считать
    int length_left = 0; //сколько осталось до конца массива (число элементов)
    int last_index = 0; //последний индекс
    int i = 0;
    int full_length = arr_length;

    while (arr_length > 1)
    {
        for(int j = 0; j < full_length; j++ ) 
            cout << arr[j] << " ";
        cout << "\t";

        cout << "i: " << i << "  ";
        cout << "arr_length: " << arr_length << "  ";

        last_index = arr_length-1;
        length_left  = (last_index - index_to_start)+1;// для (1 - 0) length_left = 2, как в хроестоматийной задаче про забор

        cout << "index_to_start: " << index_to_start << "  ";
        cout << "length_left: " << length_left << "  ";
        
        index_to_out = word_count%(length_left); //индекс того, кто выбывает; периодичность (движение по кругу) процесса реализуется через modf 
        if (index_to_out < 0) index_to_out += 1; 

        cout << "index_to_out: " << index_to_out << "  ";
        cout << "nubm_to_out: " << index_to_out+1 << "  ";

        for (int i = index_to_out; i < last_index; i++) //смещаем элементы влево
            arr[i] = arr[i+1]; //текущий элемент = следующему
        arr[last_index] = 0; //обнуляем дубликат
        arr_length--;

        index_to_start = index_to_out;

        cout << "index_to_start (new): " << index_to_start << "\t";
        i++;
        cout << endl;
    }
    return arr[0];
} */