int array_counter(int *arr, int SIZE)
{
    int counter;
    for (int i = 0; i < SIZE; i++)
    {
        if ( (i+1)%2 == 0 && arr[i]%2 != 0 ) 
        counter++;
    }
    return counter;
}