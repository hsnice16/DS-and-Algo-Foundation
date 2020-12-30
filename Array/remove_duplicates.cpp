// Implementation of problem, remove duplicates from a sorted array

#include <iostream>
using namespace std;

int remove_duplicates(int arr[], int size)
{
    int count = 1; // number of distinct value

    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[count - 1])
        {
            arr[count] = arr[i];
            count++;
        }
    }
    return count; // new size
}

int main()
{
    int size;
    cout << "\nWhat's the size of arry ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int new_size = remove_duplicates(arr, size);

    cout << "\nAfter removing duplicates : ";
    for (int i = 0; i < new_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}