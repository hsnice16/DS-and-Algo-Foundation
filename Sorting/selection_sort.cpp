// Implementation of selection sort algorithm

#include <iostream>
using namespace std;

// algo
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_ind = i; // index of minimum value
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }

        if (min_ind != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
        }
    }
}

int main()
{
    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    selection_sort(arr, size);

    cout << "\nAfter Sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}