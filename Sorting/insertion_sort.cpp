// implementation of insertion sort algorithm

#include <iostream>
using namespace std;

void insertion_sorting(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling elements in array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    insertion_sorting(arr, size);

    cout << "\nAfter sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}