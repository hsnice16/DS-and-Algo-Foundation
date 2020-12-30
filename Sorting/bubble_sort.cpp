// Implementation of bubble sort algorithm

#include <iostream>
using namespace std;

// swapping
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// algo
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool check = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                check = true;
            }
        }
        if (check == false)
            break;
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

    bubble_sort(arr, size);

    cout << "\nAfter Sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}